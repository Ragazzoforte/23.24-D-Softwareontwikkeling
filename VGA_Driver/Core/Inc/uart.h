#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>
#include "misc.h"
#include "string.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
// #include "stm32f4XX_dma.h"

#define UART_BUFFER_SIZE 100

// char UART_TX[UART_BUFFER_SIZE];
extern char UART_RX_message[UART_BUFFER_SIZE];
extern uint16_t charCnt;
extern bool msgReceivedUSART2;

// void UART_Init_DMA(void);
void UART_Init(uint32_t baudrate);
void UART_SendChar (char c);
void UART_SendString (char *string);
// char* UART_GetString (void);

#endif // UART_H