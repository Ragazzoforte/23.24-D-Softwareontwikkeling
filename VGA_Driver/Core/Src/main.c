/**
 * @brief main.c
 * 
 * This file contains the main function of the program. It initializes the system, sets up the VGA screen, and enters a loop to handle UART messages.
 * 
 * @file main.c
 * @authors Michel Vollmuller, Tim Wannet, Tijmen Willems
 * @date 5 mei 2024
 * @version 1.0
 * @pre This file must be used in combination with main.h
 * 
 */

#include "main.h"

/**
 * @brief Main function of the program.
 * 
 * This function initializes the system, sets up the VGA screen, and enters a loop to handle UART messages.
 * 
 * @return no return value
 */
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
