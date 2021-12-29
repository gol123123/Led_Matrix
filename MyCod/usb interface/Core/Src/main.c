/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"
#include "LED_MAT.h"
#include "FlashPROM.h"
#include "max7219.h"
#include <stdbool.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


char str_rx[33];
char UserData[16];
char str_tx[50];
volatile char start_rx;


myBuf_t wdata[BUFFSIZE];
bool toggle = true;
	
uint8_t TxIdx = 0, TxIdy = 0;
uint8_t RxIdx = 0, RxIdy = 0;
uint8_t CounterPin = 0;

uint16_t counter = 0;
uint32_t res_addr = 0;
/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
CRC_HandleTypeDef hcrc;
TIM_HandleTypeDef htim1;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM1_Init(void);

/* USER CODE BEGIN PFP */

void serdechkobienie(void);
void zapolnenie_serdechka(void);
void serdechko_wniz(void);
void dogdik(void);
void smiley_face(void);
void Front(void);

void WriteUserFrame(void);
void ShowUserFrame(void);


/* USER CODE END PFP */


int main(void)
 {
  HAL_Init();
	 
	uint8_t i =0;
	char *myText = "Everything will be alright";
	 
  SystemClock_Config();
  MX_CRC_Init();
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_SPI1_Init();
	 
	//MX_TIM1_Init();
	//HAL_TIM_Base_Start_IT(&htim1); 
	 
	void (*FrameShow[5])(void) = {serdechkobienie, zapolnenie_serdechka, serdechko_wniz, dogdik,smiley_face};
	//erase_flash();
	
	res_addr = flash_search_adress(STARTADDR, BUFFSIZE * DATAWIDTH);
	
  max7219_init(9);
	HAL_Delay(2000);
	
  while (1)
  {

		//max7219_SetStrirg(myText, 0, 0 );	// выводим на экран наш текст
	  FrameShow[CounterPin]();
		WriteUserFrame();
		//DataConverter();

  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

static void MX_GPIO_Init(void)
	{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 959;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 49999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 240;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/* USER CODE BEGIN 4 */
void ResetBit()
	{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
}

void EnableDecoder(uint8_t TX)
{
    switch(TX)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
            break;
        case 1:
				  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
			     	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
            break;
        case 2:
				  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
			     	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
            break;
        case 3:
			   		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
			     	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
            break;
        case 4:
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            break;
        case 5:
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
			    	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            break;
        case 6:
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            break;
        case 7:
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
				    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            break;
    }      
}

void serdechkobienie()
{
	uint8_t i=0;
	uint8_t BuffFrame[12] = {0,1,2,3,4,3,2,1,0,1,0,1};
	while(1)
	{
	   for(i =0; i <12; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
			   if(TxIdx == 8)
				 {
					 max7219_send_8(SPI_MASTER_Buffer_Tx[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send_to_all(TxIdx, SPI_MASTER_Buffer_Tx[TxIdy][TxIdx-1]);
				 }						
		    }
				HAL_Delay(500);
        max7219_clear();
				
				if(CounterPin != 0)
				{ return; } 
			}
	}
}

void zapolnenie_serdechka()
{
	uint8_t BuffFrame[21] = {5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,1,0,1,0,1,0};
		while(1)
	{
	for( uint8_t i =0; i <21; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
					if(TxIdx == 8)
				 {
					 max7219_send_8(SPI_MASTER_Buffer_Tx[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send_to_all(TxIdx, SPI_MASTER_Buffer_Tx[TxIdy][TxIdx-1]);
				 }			 
		    }
				HAL_Delay(500);
        max7219_clear();
				
				if(CounterPin != 1)
				{ return; } 
			}
	}
}

void serdechko_wniz()
{
	uint8_t BuffFrame[8] = {18,0,19,20,21,22,23,24};
  while(1)
	{
	for( uint8_t i =0; i <8; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
			   if(TxIdx == 8)
				 {
					 max7219_send_8(SPI_MASTER_Buffer_Tx[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send_to_all(TxIdx, SPI_MASTER_Buffer_Tx[TxIdy][TxIdx-1]);
				 }							
		    }
				HAL_Delay(500);
        max7219_clear();
				
				if(CounterPin != 2)
				{ return; } 
			}
	}
}

void dogdik()
{
	uint8_t BuffFrame[16] = {25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
	while(1)
	{
	for( uint8_t i =0; i <16; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
			   if(TxIdx == 8)
				 {
					 max7219_send_8(SPI_MASTER_Buffer_Tx[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send_to_all(TxIdx, SPI_MASTER_Buffer_Tx[TxIdy][TxIdx-1]);
				 }							
		    }
				HAL_Delay(200);
        max7219_clear();
				if(i == 11)
				{i=8;}
				if(CounterPin != 3)
				{ return; } 
			}
	}
}

void smiley_face()
{
	uint8_t BuffFrame[6] = {41,42,43};
	while(1)
	{
	for( uint8_t i =0; i <3; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
			   if(TxIdx == 8)
				 {
					 max7219_send_8(SPI_MASTER_Buffer_Tx[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send_to_all(TxIdx, SPI_MASTER_Buffer_Tx[TxIdy][TxIdx-1]);
				 }							
		    }
				
				HAL_Delay(1000);
        max7219_clear();
			if(CounterPin != 4)
			{ return; } 
			}
	}
}


void Front()
{
	uint8_t BuffFrame[162];
	for( uint16_t i =0; i <162; i++)
	{  BuffFrame[i] = i;  }
	while(1)
	{
	for( uint16_t i =0; i <162; i++)
		  {
				TxIdy = BuffFrame[i];
				
				for( TxIdx =1; TxIdx <9; TxIdx++)
				{
					if(TxIdx == 8)
				 {
					 max7219_send_8(MAX7219_Dot_Matrix_font[TxIdy][7]);
				 } 
				 else
				 {
					 max7219_send(TxIdx, MAX7219_Dot_Matrix_font[TxIdy][TxIdx-1],MAX7219_Dot_Matrix_font[TxIdy][TxIdx-1]);
				 }						
		    }
				HAL_Delay(500);
        max7219_clear();
//			if(CounterPin != 6)
//			{ return; } 
			}
	}
}



void WriteUserFrame()
{
	if(start_rx == 0x84)
	{
	wdata[8] = 0;
	for(RxIdx = 0; RxIdx <16; RxIdx++)
	{
	  wdata[RxIdx] = (uint16_t)( (UserData[RxIdx] << 8) | UserData[RxIdx+1] );
		RxIdx++;
	}
	write_to_flash(wdata);
  }
}

void ShowUserFrame()
{
	myBuf_t user_tx[BUFFFRAME][BUFFSIZE];
	myBuf_t rdata[BUFFSIZE] = {0,};
	uint8_t buffetFrame;
	for(RxIdy = 0; RxIdy <BUFFFRAME; RxIdy++)
	{
		read_all_data_in_flash(rdata, RxIdy); 
	  if(read_all_data_in_flash(rdata, RxIdy) == 1)
		{
		  buffetFrame = RxIdy;
		}
	  for(RxIdx = 0; RxIdx <8; RxIdx++)
   	{
  	  user_tx[RxIdy][RxIdx] = rdata[RxIdx];
  	}
	}
		
  while(counter < 13)
	{
		for(RxIdy = 0; RxIdy <buffetFrame; RxIdy++)
		{
				for(TxIdx =0; TxIdx <8; TxIdx++)
   		{
  			ResetBit();
  			EnableDecoder(TxIdx);
  		  HAL_SPI_Transmit (&hspi1, (uint8_t*)&user_tx[RxIdy][RxIdx], 2, 500);
        HAL_Delay(10);						
	   }	
		}
  }
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  if(GPIO_Pin== GPIO_PIN_8) 
	{
    CounterPin++;
		if(CounterPin>=5)
		{
			CounterPin = 0;
		}	
  }
	else if(GPIO_Pin== GPIO_PIN_9)
	{
	  CounterPin--;
		if(CounterPin == 0xff)
		{
			CounterPin = 4;
		}
	}
	else{
    __NOP();
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
        if(htim->Instance == TIM1) //check if the interrupt comes from TIM1
        {
           if(toggle)
	         {
          		HAL_SuspendTick();
              HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
          		toggle = false;
           }else
	         {
              HAL_ResumeTick();	
         	}
        }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
