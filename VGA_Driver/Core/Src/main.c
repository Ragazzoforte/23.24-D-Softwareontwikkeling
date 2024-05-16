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

  API_clearscreen("blauw");
  // API_draw_text (10, 10, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 2, 1, 1);
  // API_draw_text (10, 30, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 2, 2, 1);
  // API_draw_text (10, 50, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 2, 3, 1);
  // API_draw_text (10, 70, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 1, 1, 1);
  // API_draw_text (10, 90, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 1, 2, 1);
  // API_draw_text (10, 110, VGA_COL_RED, "Hallo mijn naam is Michel Vollmuller", "consolas", 1, 3, 1);
  API_draw_bitmap (100, 100, 7);
  
  while(1)
  {
  }
}
