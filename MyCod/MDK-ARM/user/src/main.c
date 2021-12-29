#include "stm32f10x.h"
#include "max7219.h"
//----------------------------------------------------------
#define SYSCLOCK 72000000U
//----------------------------------------------------------
#define CS_RESET() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR4)
#define CS_SET() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR4)
#define SPI1_ENABLE() SET_BIT(SPI1->CR1, SPI_CR1_SPE);
//----------------------------------------------------------
__IO uint32_t tmpreg;
__IO uint32_t SysTick_CNT = 0;
//----------------------------------------------------------
__forceinline void delay(__IO uint32_t tck)
{
  while(tck)
  {
    tck--;
  }  
}
//----------------------------------------------------------
void delay_ms(uint32_t ms)
{
  MODIFY_REG(SysTick->VAL,SysTick_VAL_CURRENT_Msk,SYSCLOCK / 1000 - 1);
  SysTick_CNT = ms;
  while(SysTick_CNT) {}
}
//-----------------------------------------------------------
void RCC_DeInit(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSION);
  while(READ_BIT(RCC->CR, RCC_CR_HSIRDY == RESET)) {}
  MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, 0x80U);
  CLEAR_REG(RCC->CFGR);
  while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RESET) {}
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
  while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RESET) {}
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON | RCC_CR_CSSON);
  while (READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET) {}
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);
  //Reset all CSR flags
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);
}
//----------------------------------------------------------
void SetSysClockTo72(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSEON);
  while(READ_BIT(RCC->CR, RCC_CR_HSERDY == RESET)) {}
  //Enable the Prefetch Buffer
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_PRFTBE);
  SET_BIT(FLASH->ACR, FLASH_ACR_PRFTBE);
  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_2);
  MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV2);
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL,
             RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL9);
  SET_BIT(RCC->CR, RCC_CR_PLLON);
  while(READ_BIT(RCC->CR, RCC_CR_PLLRDY) != (RCC_CR_PLLRDY)) {}
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
  while(READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}
}
//----------------------------------------------------------
void SysTick_Init(void)
{
  MODIFY_REG(SysTick->LOAD,SysTick_LOAD_RELOAD_Msk,SYSCLOCK / 1000 - 1);
  CLEAR_BIT(SysTick->VAL, SysTick_VAL_CURRENT_Msk);
  SET_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);
}
//----------------------------------------------------------
static void GPIO_Init(void)
{
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);
  MODIFY_REG(GPIOA->CRL,  GPIO_CRL_CNF4_1 | GPIO_CRL_CNF4_0 | GPIO_CRL_MODE4_1, GPIO_CRL_MODE4_0);
}
//----------------------------------------------------------
static void SPI_Init(void)
{
  //SPI1 GPIO
  MODIFY_REG(GPIOA->CRL, GPIO_CRL_CNF5_0 | GPIO_CRL_CNF6_1 | GPIO_CRL_CNF7_0 | GPIO_CRL_MODE6, 
                          GPIO_CRL_CNF5_1 | GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_1 | GPIO_CRL_MODE5 | GPIO_CRL_MODE7);
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);
  //RCC peripheral clock enabling
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
  //Delay after an RCC peripheral clock enabling
  tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
  //8 bit 0:0
//  MODIFY_REG(SPI1->CR1, SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE | SPI_CR1_CRCEN | SPI_CR1_CRCNEXT | \
//                        SPI_CR1_DFF | SPI_CR1_RXONLY | SPI_CR1_LSBFIRST | \
//                        SPI_CR1_BR_2 | SPI_CR1_CPOL | SPI_CR1_CPHA , \
//                        SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_BR_1 | SPI_CR1_BR_0 | SPI_CR1_MSTR);
  //16 bit 0:0
//  MODIFY_REG(SPI1->CR1, SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE | SPI_CR1_CRCEN | SPI_CR1_CRCNEXT | \
//                        SPI_CR1_RXONLY | SPI_CR1_LSBFIRST | \
//                        SPI_CR1_BR_2 | SPI_CR1_CPOL | SPI_CR1_CPHA , \
//                        SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_BR_1 | SPI_CR1_DFF | SPI_CR1_BR_0 | SPI_CR1_MSTR);
  //16 bit 1:1
  MODIFY_REG(SPI1->CR1, SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE | SPI_CR1_CRCEN | SPI_CR1_CRCNEXT | \
                        SPI_CR1_RXONLY | SPI_CR1_LSBFIRST | SPI_CR1_BR_2, \
                        SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_BR_1 | SPI_CR1_DFF | SPI_CR1_BR_0 | \
                        SPI_CR1_MSTR | SPI_CR1_CPOL | SPI_CR1_CPHA);
  CLEAR_BIT(SPI1->CR2, 0x00FF);
  
}
//----------------------------------------------------------
int main(void)
{
  uint16_t i;
  RCC_DeInit();
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
  //Delay after an RCC peripheral clock enabling
  tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
  //NOJTAG: JTAG-DP Disabled and SW-DP Enabled 
  CLEAR_BIT(AFIO->MAPR,AFIO_MAPR_SWJ_CFG);
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_JTAGDISABLE);
  SetSysClockTo72();
  SysTick_Init();
  GPIO_Init();
  SPI_Init();
  delay_ms(100);
  CS_RESET();
  CS_SET();
  SPI1_ENABLE();
  max7219_Init();
  max7219_clear();
  delay_ms(2000);
  while(1)
	{

			max7219_send(1, 0xff, 0x1a);
      delay_ms(500);
	   	max7219_clear();
		  delay_ms(500);
  }
}
//----------------------------------------------------------
void SysTick_Handler(void)
{
  if(SysTick_CNT > 0)  SysTick_CNT--;
}
//----------------------------------------------------------
