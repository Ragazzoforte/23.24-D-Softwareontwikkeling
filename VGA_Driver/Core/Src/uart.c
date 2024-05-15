/**
  ******************************************************************************
  * @file    uart.c
  * @author  Tijmen Willems
  * @brief   uart driver functions source file
  *
  *   This file provides five functions to be called from the logic_layer:
  *      - uart_init(): used to initialize the uart communication 
  *
  *      - API_draw_line(): used to draw a line to the VGA screen.  
  *                                     
  *      - API_draw_rectangle(): used to draw a rectangle to the VGA screen.
  * 
  *      - API_draw_bitmap(): used to draw a figure (bitmap) to the VGA screen.  
  * 
  *      - API_clearscreen(): used to clear the VGA screen.  
  * 
  ****************************************************************************** 
  */

/** @addtogroup VGA driver functions
  * @{
  */

#include "uart.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

void UART_Init(uint32_t baudrate)
{
    // enable GPIO A clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // enable USART2 clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // enable alternate function
    GPIOA->MODER |= (2<<4); // Bits (5:4)= 1:0 --> Alternate Function for Pin PA2
    GPIOA->MODER |= (2<<6); // Bits (7:6)= 1:0 --> Alternate Function for Pin PA3

    // select alternate function
    GPIOA->AFR[0]  |= (7<<8);   // Bites   (11:10:9:8) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA2
    GPIOA->AFR[0]  |= (7<<12);  // Bites (15:14:13:12) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA3

    // enable uart
    USART2->CR1 = 0x00;     // Clear all existing settings
    USART2->CR1 |= (0<<12); // M  = 0... 8 data bits
    USART2->CR1 |= (1<<13); // UE = 1... Enable USART

    // set the boudrate
    RCC_ClocksTypeDef clocks;
    RCC_ClocksTypeDef *clocks_ptr = &clocks;
    RCC_GetClocksFreq(clocks_ptr);
    USART2->BRR = clocks.PCLK1_Frequency/baudrate;   

    // enable rx and tx
    USART2->CR1 |= (1<<2);  // RE=1.. Enable Receiver
    USART2->CR1 |= (1<<3);  // TE=1.. Enable Transmitter
}

void UART_SendChar (char c)
{
	/*********** STEPS FOLLOWED *************
	
	1. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
		 for each data to be transmitted in case of single buffer.
	2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
		 that the transmission of the last frame is complete. This is required for instance when
		 the USART is disabled or enters the Halt mode to avoid corrupting the last transmission.
	
	****************************************/

	USART2->DR = c;   // LOad the Data
	while (!(USART2->SR & (1<<6)));  // Wait for TC to SET.. This indicates that the data has been transmitted
}

void UART_SendString (char *string)
{
	while (*string) UART2_SendChar (*string++);
}

uint8_t UART_GetChar (void)
{
		/*********** STEPS FOLLOWED *************
	
	1. Wait for the RXNE bit to set. It indicates that the data has been received and can be read.
	2. Read the data from USART_DR  Register. This also clears the RXNE bit
	
	****************************************/
	uint8_t Temp;
	
	while (!(USART2->SR & (1<<5)));  // Wait for RXNE to SET.. This indicates that the data has been Received
	Temp = USART2->DR;  // Read the data. 
	return Temp;
}

/**
  * @}
  */