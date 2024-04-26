/**
  ******************************************************************************
  * @file    vga_driver.c
  * @author  Tijmen Willems
  * @brief   VGA driver functions source file
  *
  *   This file provides five functions to be called from the logic_layer:
  *      - API_draw_text(): used to draw a string to the VGA screen. 
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

#include "main.h"
#include "vga_driver.h"

/**
  * @brief  API_draw_text() is used to draw a string to the VGA screen.  
  *           
  * @note   selected font must be a certain format         
  *     
  * @param  
  * @retval 
  */
int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved) // fontsize:1 small, 2 big
{

}

/**
  * @brief  API_draw_line() is used to draw a line to the VGA screen.  
  *           
  * @note   Select the shape of the line ending with the last parameter.         
  *     
  * @param  
  * @retval 
  */
int API_draw_line (int x_1, int y_1, int x_2, int y2, int color, int weight, int reserved)
{

}

/**
  * @brief  API_draw_rectangle() is used to draw a rectangle to the VGA screen.  
  *           
  * @note   To draw a rotated rectangle use 'API_draw_line()'   
  *     
  * @param  
  * @retval 
  */
int API_draw_rectangle (int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2) // e.g.: weight, bordercolor
{

}

/**
  * @brief  API_draw_bitmap() is used to draw a figure (bitmap) to the VGA screen.  
  *           
  * @note   selected picture must not exceed a certain size         
  *     
  * @param  
  * @retval 
  */
int API_draw_bitmap (int x_lup, int y_lup, int bm_nr)
{

}

/**
  * @brief  API_clearscreen() is used to clear the VGA screen.  
  *           
  * @note   selected color must be predefined         
  *     
  * @param  
  * @retval 
  */
int API_clearscreen (int color)
{

}

/**
  * @}
  */