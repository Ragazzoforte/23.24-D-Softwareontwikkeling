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
//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "main.h"

//--------------------------------------------------------------

//--------------------------------------------------------------
// Defines
//--------------------------------------------------------------
#define ZWART         540422306
#define LICHTMAGENTA  338820699
#define MAGENTA       3940791655
#define BLAUW         511564997
#define LICHTBLAUW    1778211001
#define CYAAN         513217430
#define LICHTCYAAN    1779863434
#define GROEN         517724933
#define LICHTGROEN    1784370937
#define GEEL          15674151
#define ROOD          16080670
#define LICHTROOD     4089130130
#define BRUIN         511801994
#define GRIJS         517718569
#define WIT           492542
//--------------------------------------------------------------

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
  * @brief Draw a line on the VGA screen.  
  *           
  * @note  This function uses the Bresenham's line algorithm to draw a line on the VGA screen.
  * 
  * @param x1: the x-coordinate of the starting point of the line
  * @param y1: the y-coordinate of the starting point of the line
  * @param x2: the x-coordinate of the ending point of the line
  * @param y2: the y-coordinate of the ending point of the line
  * @param colour: the colour of the line
  * @param weight: the weight/thicknes of the line
  * @param reserved: reserved for future use
  * 
  * @retval none 
  */
int API_draw_line (int x1, int y1, int x2, int y2, int colour, int thickness, int reserved)
{
  int x_difference = x2 - x1; //calculate the difference in x-coordinates
  int y_difference = y2 - y1; //calculate the difference in y-coordinates
  int step_x = x1 < x2 ? 1 : -1; //set the step size for the x-coordinate
  int step_y = y1 < y2 ? 1 : -1; //set the step size for the y-coordinate
  int slope_error = (x_difference > y_difference ? x_difference : -y_difference) / 2; //calculate the error
  int store_error;
  
  if (x1 < 0 || x1 >= VGA_DISPLAY_X || x2 < 0 || x2 >= VGA_DISPLAY_X || y1 < 0 || y1 >= VGA_DISPLAY_Y || y2 < 0 || y2 >= VGA_DISPLAY_Y) // Check if the coordinates are out of the screen
  {
    // Handle the error here
    return -1;
  }
  
  while (1<2) 
  {
    UB_VGA_SetPixel(x1, y1, colour);
    if (x1 == x2 && y1 == y2) //check if the end of the line is reached
    { 
      break; 
    }
    
    store_error = slope_error; //store the error

    if (store_error > -x_difference) //check if the error is larger than the negative x-difference
    { 
      slope_error -= y_difference; //update error
      x1 += step_x; //update x-coordinate
    }
    
    if (store_error < y_difference) //check if the error is smaller than the y-difference
    {
      slope_error += x_difference; //update error
      y1 += step_y; //update y-coordinate
    }

    for (int i=0 ; i<thickness ; i++) //draw the line, including the specified weight
    {
      UB_VGA_SetPixel(x1 + i, y1, colour);
    }
  }
  return 0;
}

/**
  * @brief  API_draw_rectangle() is used to draw a rectangle to the VGA screen.  
  *           
  * @note   To draw a rotated rectangle use 'API_draw_line()'   
  *     
  * @param x: the x-coordinate of the top-left corner of the rectangle
  * @param y: the y-coordinate of the top-left corner of the rectangle
  * @param width: the width of the rectangle
  * @param height: the height of the rectangle
  * @param colour: the colour of the rectangle
  * @param filled: whether the rectangle should be filled in or not
  * @param reserved1: reserved for future use
  * @param reserved2: reserved for future use
  * 
  * @retval
  */
int API_draw_rectangle (int x, int y, int width, int height, int colour, int filled, int reserved1, int reserved2) // e.g.: weight, bordercolor
{
  if (x < 0 || x >= VGA_DISPLAY_X || y < 0 || y >= VGA_DISPLAY_Y || width <= 0 || height <= 0) // Check if the coordinates or dimensions are invalid
  {
    // Handle the error here
    return -1;
  }
  
  API_draw_line(x, y, x + width, y, colour, 1, reserved1); // Draw the top line
  
  // Draw the bottom line
  API_draw_line(x, y + height, x + width, y + height, colour, 1, reserved1);
  
  // Draw the left line
  API_draw_line(x, y, x, y + height, colour, 1, reserved1);
  
  // Draw the right line
  API_draw_line(x + width, y, x + width, y + height, colour, 1, reserved1);
  
  if (filled) // Check if the rectangle should be filled
  {
    for (int i = 1; i < height; i++) // Iterate over the rows of the rectangle
    {
      API_draw_line(x, y + i, x + width, y + i, colour, 1, reserved1); // Draw a horizontal line for each row
    }
  }
  
  return 0;
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
  * @note   selected color must be predefined, valid colours: zwart, lichtmagenta, magenta, blauw, lichtblauw, cyaan, lichtcyaan groen, lichtgroen, geel, rood, lichtrood, bruin, grijs, wit    
  *     
  * @param colour: the color to clear the screen with
  * @retval none
  */
int API_clearscreen (char *colour)
{
  unsigned long colour_choice = hash(colour); //convert the string to a unique value for the switch case

  switch (colour_choice) 
  {
    case ZWART:
    UB_VGA_FillScreen(VGA_COL_BLACK); //VGA display is cleared with the colour: zwart
      break;
    case LICHTMAGENTA:
      UB_VGA_FillScreen(VGA_COL_LIGHT_MAGENTA); //VGA display is cleared with the colour: lichtmagenta
      break;
    case MAGENTA:
      UB_VGA_FillScreen(VGA_COL_MAGENTA); //VGA display is cleared with the colour: magenta
      break;
    case BLAUW:
      UB_VGA_FillScreen(VGA_COL_BLUE); //VGA display is cleared with the colour: blauw
      break;
    case LICHTBLAUW:
      UB_VGA_FillScreen(VGA_COL_LIGHT_BLUE); //VGA display is cleared with the colour: lichtblauw
      break;
    case CYAAN:
      UB_VGA_FillScreen(VGA_COL_CYAN); //VGA display is cleared with the colour: cyaan
      break;
    case LICHTCYAAN:
      UB_VGA_FillScreen(VGA_COL_LIGHT_CYAN); //VGA display is cleared with the colour: lichtcyaan
      break;
    case GROEN:
      UB_VGA_FillScreen(VGA_COL_GREEN); //VGA display is cleared with the colour: groen
      break;
    case LICHTGROEN:
      UB_VGA_FillScreen(VGA_COL_LIGHT_GREEN); //VGA display is cleared with the colour: lichtgroen
      break;
    case GEEL:
      UB_VGA_FillScreen(VGA_COL_YELLOW); //VGA display is cleared with the colour: geel
      break;
    case ROOD:
      UB_VGA_FillScreen(VGA_COL_RED); //VGA display is cleared with the colour: rood
      break;
    case LICHTROOD:
      UB_VGA_FillScreen(VGA_COL_LIGHT_RED); //VGA display is cleared with the colour: lichtrood
      break;
    case BRUIN:
      UB_VGA_FillScreen(VGA_COL_BROWN); //VGA display is cleared with the colour: bruin
      break;
    case GRIJS:
      UB_VGA_FillScreen(VGA_COL_GREY); //VGA display is cleared with the colour: grijs
      break;
    case WIT:
      UB_VGA_FillScreen(VGA_COL_WHITE); //VGA display is cleared with the colour: wit
      break;
    default:
      // Code to handle invalid color input
      break;
  }
return 0;
}

/**
  * @brief hash() is used to hash a string to a unique value. 
  *           
  * @note  This function is used to generate a unique value for the string.   
  *     
  * @param str: the string to be hashed
  * @retval unsigned long: the hashed value of the string
  */
unsigned long hash(char *str) {
    unsigned long hash = 10; //seed value for spreading out the hash values
    int c;

    while ((c = *str++)) //iterate over the string
        hash = ((hash << 5) + hash) + c;
    return hash;
}
/**
  * @}
  */