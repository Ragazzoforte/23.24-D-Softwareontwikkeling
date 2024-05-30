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
#include "stm32f4xx_it.h"

#define BAUD_RATE 115200

int main(void)
{	
  SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  // UB_VGA_FillScreen(VGA_COL_RED); // Fill screen with red color

  // API_draw_polygon(50, 50, 25, 5, VGA_COL_BLUE, 1); // Draw a blue pentagon

  // //lijn, x, y, x’, y’, kleur, dikte
  // // char *myStrings[7] = {"lijn", "25", "80", "100", "110", "lichtblauw", "2"}; 

  // //rechthoek, x_lup, y_lup, breedte, hoogte, kleur, gevuld (1,0) [als 1: rand (1px) met kleur]
  // // char *myStrings[8] = {"rechthoek", "25", "80", "100", "110", "blauw", "0"}; 

  // // tekst, x, y, kleur, tekst, fontnaam (arial, consolas), fontgrootte (1,2), fontstijl (normaal, vet, cursief)
  // char *myStrings[8] = {"tekst", "25", "80", "blauw", "Hello Michel", "arial", "1", "cursief"};

  // //bitmap, nr, x-lup, y-lup
  // // char *myStrings[4] = {"bitmap", "7", "100", "100"}; 

  // //clearscherm, kleur
  // // char *myStrings[2] = {"clearscherm", "blauw"}; 
  // int a = kiezen(myStrings, 7);
	UB_VGA_FillScreen(VGA_COL_WHITE);

  UART_Init(BAUD_RATE);

  UART_SendString(" "); // First char (weird bug)
  UART_SendString("ik ben een stm32F407 maar koalaberen zijn ook erg mooie beesten");
  while(true)
  {
    if(msgReceivedUSART2 == true)
    {
      UART_SendString(UART_RX_message);

      int a = kiezen(UI_string_to_function(UART_RX_message));

      memset(UART_RX_message, 0, UART_BUFFER_SIZE);
      msgReceivedUSART2 = false; // reset message flag
    }
  }
}
