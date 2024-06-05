//--------------------------------------------------------------
// File     : main.c
// Datum    : 05.06.2024
// Version  : 1.1
// Autor    : UB
// mods by	: Michel Vollmuller, Tim Wannet en Tijmen Willems
// CPU      : STM32F4
// IDE      : Microsoft VSCode 1.89.1
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_driver 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"

#define BAUD_RATE 115200

int main(void)
{	
  SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(VGA_COL_WHITE);
  API_draw_polygon(50, 50, 25, 5, VGA_COL_BLUE, 1); // Draw a blue pentagon

  UART_Init(BAUD_RATE);

  UART_SendString(" "); // First char (weird bug)
  UART_SendString("ik ben een stm32F407 maar koalaberen zijn ook erg mooie beesten");
  while(true)
  {
    if(msgReceivedUSART2 == true)
    {
      UART_SendString(UART_RX_message);
      kiezen(UI_string_to_function(UART_RX_message));
      memset(UART_RX_message, 0, UART_BUFFER_SIZE);
      msgReceivedUSART2 = false; // reset message flag
    }
  }
}
