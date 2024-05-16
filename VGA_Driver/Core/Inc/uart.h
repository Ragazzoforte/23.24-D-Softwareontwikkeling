#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

#define UART_BUFFER_SIZE 100

void UART_Init_IRQ(void);
void UART_Init_DMA(void);
void UART_Init(uint32_t baudrate);
void UART_SendChar (char c);
void UART_SendString (char *string);
uint8_t UART_GetChar (void);

#endif // UART_H