#include "max7219.h"

char dg=8;

#define cs_set() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR4)
#define cs_reset() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR4)

#define MAX7219_CHIPS        2


__attribute__((always_inline)) static inline void send_data(uint8_t reg, uint8_t data) {
    SPI1->DR = (uint16_t)( (reg << 8) | data );
    while ( (SPI1->SR & SPI_SR_BSY) == SPI_SR_BSY);
}

void max7219_send_to_all(const uint8_t reg, const uint8_t data) {
    cs_set();
    for (uint32_t i = 0; i < MAX7219_CHIPS; i++) {
        send_data(reg, data);
    }
    cs_reset();
}

void max7219_send_to_chip(const uint8_t reg, const uint8_t data, const uint8_t chip)
	{
    if (chip > MAX7219_CHIPS) 
		{ return; }
		
    cs_set();
    for (uint32_t i = 0; i < MAX7219_CHIPS; i++) {
        if ( (MAX7219_CHIPS - i - 1) == chip)
            send_data(reg, data);
        else
            send_data(REG_NO_OP, data);
    }
    cs_reset();
}
	
void max7219_send(const uint8_t reg, const uint8_t data_0, const uint8_t data_1) 
{
    cs_set();
    send_data(reg, data_0);
    send_data(reg, data_1);
    cs_reset();
}

void max7219_test(void) {
    max7219_send_to_all(REG_DIGIT_0, 0x01);
    max7219_send_to_all(REG_DIGIT_1, 0x02);
    max7219_send_to_all(REG_DIGIT_2, 0x04);
    max7219_send_to_all(REG_DIGIT_3, 0x08);
    max7219_send_to_all(REG_DIGIT_4, 0x0F);
    max7219_send_to_all(REG_DIGIT_5, 0x10);
    max7219_send_to_all(REG_DIGIT_6, 0x12);
    max7219_send_to_all(REG_DIGIT_7, 0x14);
}

void max7219_clear(void) {
    for (uint32_t i = 0; i < 8; i++) {
        max7219_send_to_all(REG_DIGIT_0 + i, 0x00);
    }
}

//-------------------------------------------------------
void max7219_Init  (void)
{
  send_data(0x0F,0x00);//отключим режим тестирования
  send_data(0x09,0x00);//включим режим декодирования
  send_data(0x0B,0x0f);//кол-во используемых разрядов
  send_data(0x0A,0x06);//интенсивность свечения
  send_data(0x0C,0x01);//включим индикатор
  max7219_clear();
}
