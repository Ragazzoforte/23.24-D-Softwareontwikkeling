/**
/**
 * @brief This file contains the implementation of the uart communication.
 * 
 * @file uart.c
 * @authors Michel Vollmuller, Tim Wannet, Tijmen Willems
 * @date 5 mei 2024
 * @version 1.0
 * @pre This file must be used in combination with main.h
 * 
 */

/** @addtogroup VGA driver functions
  * @{
  */

#include "uart.h"

char UART_TX_message[UART_BUFFER_SIZE];
char UART_RX_message[UART_BUFFER_SIZE];
uint16_t charCnt = 0;
bool msgReceivedUSART2 = false;

void USART2_IRQHandler(void)
{
  if(USART2->SR & (1<<4))
  {
    // UART IDLE interrupt (Idle line)
    // USART2->CR1 ^= (1<<4); // Disable idle line interrupt
    // USART2->SR &= ~(1<<4);
    volatile uint32_t tempreg;
    tempreg = USART2->SR;
    (void) tempreg;
    tempreg = USART2->DR;
    (void) tempreg;
    
  	msgReceivedUSART2 = true;
    charCnt = 0;
  }

  if(USART2->SR & (1<<5))
  {
    // USART RX interrupt
    //if(charCnt == 0) USART2->CR1 ^= (1<<4); // Enable idle line interrupt
    if (USART2->DR != 0)
		{
			UART_RX_message[charCnt] = USART2->DR;
			charCnt++;
		}
  }

  if(USART2->SR & (1<<6))
  {
    // UART TC interrupt (Transmission complete)

  }

  if(USART2->SR & (1<<7))
  {
    // UART TXE interrupt (Transmit data register empty)
  }
}

/**
  * @brief  Initializes the UART interface.
  * @param  boudrate: set the transmision boudrate, common values are:
  *         @arg 1200
  *         @arg 2400
  *         @arg 4800
  *         @arg 9600
  *         @arg 19200
  *         @arg 38400
  *         @arg 57600
  *         @arg 115200
  * @retval None
  */

void UART_Init(uint32_t baudrate)
{
    // Configure RCC
    // RCC->AHB1ENR ^= RCC_AHB1ENR_DMA1EN;   // Enable DMA clock  
    RCC->AHB1ENR ^= RCC_AHB1ENR_GPIOAEN;  // Enable GPIO-A clock
    RCC->APB1ENR ^= RCC_APB1ENR_USART2EN; // Enable USART2 clock
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_APB1Periph_USART2 /*| RCC_AHB1Periph_DMA1*/, ENABLE); // Enable GPIO-A, USART2 and DMA1 clocks

    // Enable alternate function
    GPIOA->MODER ^= (2<<4); // Bits (5:4)= 1:0 --> Alternate Function for Pin PA2
    GPIOA->MODER ^= (2<<6); // Bits (7:6)= 1:0 --> Alternate Function for Pin PA3

    // Select alternate function
    GPIOA->AFR[0]  ^= (7<<8);   // Bites   (11:10:9:8) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA2
    GPIOA->AFR[0]  ^= (7<<12);  // Bites (15:14:13:12) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA3

    //***** [UART SETTINGS]*****//
    RCC_ClocksTypeDef clocks;
    RCC_ClocksTypeDef *clocks_ptr = &clocks;
    RCC_GetClocksFreq(clocks_ptr);
    USART2->BRR = clocks.PCLK1_Frequency/baudrate;  // set the boudrate
    
    USART2->CR1 = 0x00;     // Clear all existing CR1 settings
    USART2->CR1 ^= (1<<2);  // RE=1.. Enable Receiver
    USART2->CR1 ^= (1<<3);  // TE=1.. Enable Transmitter
    USART2->CR1 ^= (1<<4);  // IDLEIE = 1... Enable 'Idle line' interrupt
    USART2->CR1 ^= (1<<5);  // RXNEIE = 1... Enable 'Data register not empty' interrupt
    // USART2->CR1 ^= (1<<6);  // TCIE = 1... Enable 'Transmission complete' interrupt
    // USART2->CR1 ^= (1<<7);  // TXEIE = 1... Enable 'Trasmit data register empty' interrupt
    
    USART2->CR2 = 0x00;     // Clear all existing CR2 settings
    USART2->CR3 = 0x00;     // Clear all existing CR3 settings

    USART2->CR1 ^= (1<<13); // Enable USART I.E. GO!!!
    NVIC_EnableIRQ(USART2_IRQn);
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
	USART2->DR = c;   // Load the Data
	while (!(USART2->SR & (1<<6)));  // Wait for TC to SET.. This indicates that the data has been transmitted
}


/**
  * @brief  Sends a single character over the UART interface. the function blocks untill the character is send.
  * @param  string: any ascii character to be sent
  * @retval None
  */
void UART_SendString (char *string)
{
  USART2->CR1 ^= (1<<5); // disable RXNE
  strcpy(UART_TX_message, string);
  
  uint8_t i;
  for(i=0 ;i< (int)strlen(string); ++i)
  {
    UART_SendChar(*(string+i));
    // string++;
  }
  UART_SendChar(10); //newline
  memset(UART_TX_message, 0, UART_BUFFER_SIZE); // clear buffer
  USART2->CR1 ^= (1<<5); // enable RXNE
}
