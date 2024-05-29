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
#include "stm32f4xx_it.h"
// #include <math.h>

// #define x_lup 10
// #define y_lup 10
// #define color 0xFF
// #define text "Hello"
// #define fontname "arial"
// #define fontsize 1
// #define fontstyle 1
// #define reserved 0

int main(void)
{	
  SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_RED); // Fill screen with red color

  API_draw_polygon(50, 50, 25, 5, VGA_COL_BLUE, 1); // Draw a blue pentagon
  char* first_word;
  char str[] = "hello, I, am";
  first_word = UI_string_to_function(str);
  int a;
  while(1)
  {
  }
}
