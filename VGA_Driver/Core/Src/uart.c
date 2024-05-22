/**
  ******************************************************************************
  * @file    uart.c
  * @author  Tijmen Willems
  * @brief   uart driver functions source file
  *
  *   This file provides five functions to be called from the logic_layer:
  *      - uart_init(): used to initialize the uart communication  
  * 
  ****************************************************************************** 
  */

/** @addtogroup VGA driver functions
  * @{
  */

#include "uart.h"
#include "misc.h"
#include "string.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4XX_dma.h"

char UART_TX[UART_BUFFER_SIZE];
char UART_RX[UART_BUFFER_SIZE];

void DMA1_Stream5_IRQHandler(void) // UART RX
{
  if(DMA_GetITStatus(DMA1_Stream5, DMA_IT_TCIF5))
  {
    // UART RX Transfer complete interrupt

  }

  if(DMA_GetITStatus(DMA1_Stream5, DMA_IT_TEIF5))
  {
    // UART RX Transfer error interrupt

  }
}

void DMA1_Stream6_IRQHandler(void) // UART TX
{
  if(DMA_GetITStatus(DMA1_Stream6, DMA_IT_TCIF6))
  {
    // UART TX Transfer complete interrupt

  }

  if(DMA_GetITStatus(DMA1_Stream6, DMA_IT_TEIF6))
  {
    // UART TX Transfer error interrupt

  }
}

void USART2_IRQHandler(void)
{
  if(USART2->SR & (1<<5))
  {
    // USART RX interrupt

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

void UART_Init_DMA(void)
{
    // Enable interrupts
    NVIC_EnableIRQ(DMA1_Stream5_IRQn);
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);

    // configure RX
    DMA_InitTypeDef DMA_USART2_RX;

    DMA_Cmd(DMA1_Stream5, DISABLE);
    DMA_DeInit(DMA1_Stream5);
    DMA_USART2_RX.DMA_Channel = DMA_Channel_4;
    DMA_USART2_RX.DMA_Memory0BaseAddr = (uint32_t)UART_RX;        // memory address
    DMA_USART2_RX.DMA_PeripheralBaseAddr = USART2->DR;        // UART address
    DMA_USART2_RX.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_USART2_RX.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;
    DMA_USART2_RX.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_USART2_RX.DMA_Mode = DMA_Mode_Normal;
    DMA_USART2_RX.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_USART2_RX.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_USART2_RX.DMA_BufferSize = UART_BUFFER_SIZE;
    DMA_USART2_RX.DMA_Priority = DMA_Priority_Medium;
    DMA_USART2_RX.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_USART2_RX.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_USART2_RX.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_Init(DMA1_Stream5, &DMA_USART2_RX);

    // configure TX
    DMA_InitTypeDef DMA_USART2_TX;

    DMA_Cmd(DMA1_Stream6, DISABLE);
    DMA_DeInit(DMA1_Stream6);
    DMA_USART2_TX.DMA_Channel = DMA_Channel_4;
    DMA_USART2_TX.DMA_Memory0BaseAddr = (uint32_t)UART_TX;        // memory address
    DMA_USART2_TX.DMA_PeripheralBaseAddr = USART2->DR;        // UART address
    DMA_USART2_TX.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_USART2_TX.DMA_PeripheralDataSize = DMA_MemoryDataSize_Byte;
    DMA_USART2_TX.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_USART2_TX.DMA_Mode = DMA_Mode_Normal;
    DMA_USART2_TX.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_USART2_TX.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_USART2_TX.DMA_BufferSize = UART_BUFFER_SIZE;
    DMA_USART2_TX.DMA_Priority = DMA_Priority_Medium;
    DMA_USART2_TX.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_USART2_TX.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_USART2_TX.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_Init(DMA1_Stream6, &DMA_USART2_TX);

    //DMA_Cmd(DMA1_Stream5, ENABLE);
    //DMA_Cmd(DMA1_Stream6, ENABLE);
}

void UART_Init(uint32_t baudrate)
{
    // configure RCC
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;   // Enable DMA clock  
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // Enable GPIO-A clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN; // Enable USART2 clock
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_APB1Periph_USART2 | RCC_AHB1Periph_DMA1, ENABLE); // Enable GPIO-A, USART2 and DMA1 clocks

    // init DMA
    //UART_Init_DMA();

    // enable alternate function
    GPIOA->MODER |= (2<<4); // Bits (5:4)= 1:0 --> Alternate Function for Pin PA2
    GPIOA->MODER |= (2<<6); // Bits (7:6)= 1:0 --> Alternate Function for Pin PA3

    // select alternate function
    GPIOA->AFR[0]  |= (7<<8);   // Bites   (11:10:9:8) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA2
    GPIOA->AFR[0]  |= (7<<12);  // Bites (15:14:13:12) = 0:1:1:1  --> AF7 Alternate function for USART2 at Pin PA3

    //***** [UART SETTINGS]*****//
    RCC_ClocksTypeDef clocks;
    RCC_ClocksTypeDef *clocks_ptr = &clocks;
    RCC_GetClocksFreq(clocks_ptr);
    USART2->BRR = clocks.PCLK1_Frequency/baudrate;  // set the boudrate
    
    USART2->CR1 = 0x00;     // Clear all existing CR1 settings
    USART2->CR1 |= (1<<2);  // RE=1.. Enable Receiver
    USART2->CR1 |= (1<<3);  // TE=1.. Enable Transmitter
    USART2->CR1 |= (1<<5);  // RXNEIE = 1... Enable 'Data register not empty' interrupt
    USART2->CR1 |= (1<<6);  // TCIE = 1... Enable 'Transmission complete' interrupt
    USART2->CR1 |= (1<<7);  // TXEIE = 1... Enable 'Trasmit data register empty' interrupt
    
    USART2->CR2 = 0x00;     // Clear all existing CR2 settings
    USART2->CR3 = 0x00;     // Clear all existing CR3 settings
    USART2->CR3 |= (1<<6);  // DMA enable receiver
    USART2->CR3 |= (1<<7);  // DMA enable transmitter

    NVIC_EnableIRQ(USART2_IRQn);
    USART2->CR1 |= (1<<13); // Enable USART I.E. GO!!!
}


//=============================================== [ Functions ] ===============================================//

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

void UART_SendString (char *string)
{
  //DMA_Cmd(DMA1_Stream6, ENABLE);
	strcpy(UART_TX, string);
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