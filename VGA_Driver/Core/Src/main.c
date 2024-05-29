//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include "uart.h"

#define BAUD_RATE 115200

int main(void)
{
	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_WHITE);

  UART_Init(BAUD_RATE);

  UART_SendString("ik ben een stm32F407 maar koalaberen zijn ook erg mooie beesten");
  while(true)
  {
    if(msgReceivedUSART2 == true)
    {
      msgReceivedUSART2 = false; // reset message flag
      UART_SendString(UART_RX_message); // do something with message
      memset(UART_RX_message, 0, UART_BUFFER_SIZE); // clear buffer for next message (optional)
    }
  }
}
