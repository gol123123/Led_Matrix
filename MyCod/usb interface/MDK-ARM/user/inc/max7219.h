#ifndef MAX7219_H_
#define MAX7219_H_

#include "stm32f10x.h"
#include <stdint.h>

#define REG_NO_OP            0x00
#define REG_DIGIT_0          0x01
#define REG_DIGIT_1          0x02
#define REG_DIGIT_2          0x03
#define REG_DIGIT_3          0x04
#define REG_DIGIT_4          0x05
#define REG_DIGIT_5          0x06
#define REG_DIGIT_6          0x07
#define REG_DIGIT_7          0x08
#define REG_DECODE_MODE      0x09
#define REG_INTENSITY        0x0A
#define REG_SCAN_LIMIT       0x0B
#define REG_SHUTDOWN         0x0C
#define REG_DISPLAY_TEST     0x0F



__attribute__((always_inline)) static inline void send_data(uint8_t reg, uint8_t data);
void max7219_send_to_all(const uint8_t reg, const uint8_t data);
void max7219_send_to_chip(const uint8_t reg, const uint8_t data, const uint8_t chip);
void max7219_send(const uint8_t reg, const uint8_t data_0, const uint8_t data_1);
void max7219_test(void);
void max7219_clear(void);
void max7219_Init (void);


#endif /* MAX7219_H_ */
