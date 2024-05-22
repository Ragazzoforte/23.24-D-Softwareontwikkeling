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

#define PI 3.14159265
#define TERMS 4

#define UNUSED(x) (void)(x)
const double cos_table[73] = {
    1.0000000, 0.9961947, 0.9848078, 0.9659258, 0.9396926, 
    0.9063078, 0.8660254, 0.8191520, 0.7660444, 0.7071068, 
    0.6427876, 0.5735764, 0.5000000, 0.4226183, 0.3420201, 
    0.2588190, 0.1736482, 0.0871557, 0.0000000, -0.0871557, 
    -0.1736482, -0.2588190, -0.3420201, -0.4226183, -0.5000000, 
    -0.5735764, -0.6427876, -0.7071068, -0.7660444, -0.8191520, 
    -0.8660254, -0.9063078, -0.9396926, -0.9659258, -0.9848078, 
    -0.9961947, -1.0000000, -0.9961947, -0.9848078, -0.9659258, 
    -0.9396926, -0.9063078, -0.8660254, -0.8191520, -0.7660444, 
    -0.7071068, -0.6427876, -0.5735764, -0.5000000, -0.4226183, 
    -0.3420201, -0.2588190, -0.1736482, -0.0871557, -0.0000000, 
    0.0871557, 0.1736482, 0.2588190, 0.3420201, 0.4226183, 
    0.5000000, 0.5735764, 0.6427876, 0.7071068, 0.7660444, 
    0.8191520, 0.8660254, 0.9063078, 0.9396926, 0.9659258, 
    0.9848078, 0.9961947, 1.0000000, 0.9961947, 0.9848078, 
    0.9659258, 0.9396926, 0.9063078, 0.8660254, 0.8191520, 
    0.7660444, 0.7071068, 0.6427876, 0.5735764, 0.5000000
};
const double sin_table[73] = {
    0.0000000, 0.0871557, 0.1736482, 0.2588190, 0.3420201, 
    0.4226183, 0.5000000, 0.5735764, 0.6427876, 0.7071068, 
    0.7660444, 0.8191520, 0.8660254, 0.9063078, 0.9396926, 
    0.9659258, 0.9848078, 0.9961947, 1.0000000, 0.9961947, 
    0.9848078, 0.9659258, 0.9396926, 0.9063078, 0.8660254, 
    0.8191520, 0.7660444, 0.7071068, 0.6427876, 0.5735764, 
    0.5000000, 0.4226183, 0.3420201, 0.2588190, 0.1736482, 
    0.0871557, 0.0000000, -0.0871557, -0.1736482, -0.2588190, 
    -0.3420201, -0.4226183, -0.5000000, -0.5735764, -0.6427876, 
    -0.7071068, -0.7660444, -0.8191520, -0.8660254, -0.9063078, 
    -0.9396926, -0.9659258, -0.9848078, -0.9961947, -1.0000000, 
    -0.9961947, -0.9848078, -0.9659258, -0.9396926, -0.9063078, 
    -0.8660254, -0.8191520, -0.7660444, -0.7071068, -0.6427876, 
    -0.5735764, -0.5000000, -0.4226183, -0.3420201, -0.2588190, 
    -0.1736482, -0.0871557, -0.0000000, 0.0871557, 0.1736482, 
    0.2588190, 0.3420201, 0.4226183, 0.5000000, 0.5735764, 
    0.6427876, 0.7071068, 0.7660444, 0.8191520, 0.8660254, 
    0.9063078, 0.9396926, 0.9659258, 0.9848078, 0.9961947, 
    1.0000000
};
//--------------------------------------------------------------
// double fast_cos(int angle);
// double fast_sin(int angle);
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
  int x_difference = abs(x2 - x1); //calculate the difference in x-coordinates
  int y_difference = abs(y2 - y1); //calculate the difference in y-coordinates
  int step_x = x1 < x2 ? 1 : -1; //set the step size for the x-coordinate
  int step_y = y1 < y2 ? 1 : -1; //set the step size for the y-coordinate
  int slope_error = (x_difference > y_difference ? x_difference : -y_difference)/2; //calculate the error
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
  UNUSED(reserved);
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
  
  API_draw_line(x, y + height, x + width, y + height, colour, 1, reserved1); // Draw the bottom line
  
  API_draw_line(x, y, x, y + height, colour, 1, reserved1); // Draw the left line

  API_draw_line(x + width, y, x + width, y + height, colour, 1, reserved1);   // Draw the right line
  
  if (filled == 1) // Check if the rectangle should be filled
  {
    for (int i = 1; i < height; i++) // Iterate over the rows of the rectangle
    {
      API_draw_line(x, y + i, x + width, y + i, colour, 1, reserved1); // Draw a horizontal line for each row
    }
  }
  UNUSED(reserved1);
  UNUSED(reserved2);
  return 0;
}

/**
  * @brief  API_draw_polygon() is used to draw a polygon to the VGA screen.  
  *           
  * @note   selected polygon must not exceed a certain size         
  *     
  * @param  
  * @retval 
  */
int API_draw_polygon (int x, int y, int corners, int colour, int filled)
{
  // if (corners < 3) // Check if the number of corners is valid
  // {
  //   // Handle the error here
  //   return -1;
  // }

  int angle = 360 / corners; // Calculate the angle between each corner
  int radius = 25; // Set the radius of the polygon

  int x_center = x; // Calculate the x-coordinate of the center of the polygon
  int y_center = y; // Calculate the y-coordinate of the center of the polygon

  int x_first = x_center + radius; // Calculate the x-coordinate of the first corner
  int y_first = y_center; // Calculate the y-coordinate of the first corner

  int x_prev = x_first; // Initialize the previous corner's x-coordinate
  int y_prev = y_first; // Initialize the previous corner's y-coordinate

  double cos, sin;
  int x_curr, y_curr;
  int index = 0;

  for (int i = 1  ; i <= corners; i++) // Iterate over each corner of the polygon
  {
    index = (angle* i) / 5;
    cos = cos_table[index];
    sin = sin_table[index];
    x_curr = x_center + (radius * cos); // Calculate the x-coordinate of the current corner
    y_curr = y_center - (radius * sin); // Calculate the y-coordinate of the current corner
  
    API_draw_line(x_prev, y_prev, x_curr, y_curr, colour, 1, 0); // Draw a line between the previous and current corner
    
    if (filled == 1) // Check if the polygon should be filled
    {
      int y_min = y_prev < y_curr ? y_prev : y_curr; // Find the minimum y-coordinate
      int y_max = y_prev > y_curr ? y_prev : y_curr; // Find the maximum y-coordinate
      
      for (int j = y_min + 1; j < y_max; j++) // Iterate over the rows between the minimum and maximum y-coordinate
      {
      int x_intersection = ((j - y_prev) * (x_curr - x_prev)) / (y_curr - y_prev) + x_prev; // Calculate the x-coordinate of the intersection point
      
      if (x_intersection < x_prev) // Check if the intersection point is to the left of the previous corner
      {
        for (int k = x_intersection; k < x_prev; k++) // Iterate over the columns between the intersection point and the previous corner
        {
        API_draw_line(k, j, x_prev, j, colour, 1, 0); // Draw a horizontal line for each column
        }
      }
      else // The intersection point is to the right of the previous corner
      {
        for (int k = x_prev + 1; k <= x_intersection; k++) // Iterate over the columns between the previous corner and the intersection point
        {
        API_draw_line(x_prev, j, k, j, colour, 1, 0); // Draw a horizontal line for each column
        }
      }
      }
    }
    x_prev = x_curr; // Update the previous corner's x-coordinate
    y_prev = y_curr; // Update the previous corner's y-coordinate
  }

  // Close the polygon by drawing a line from the last corner to the first one
  API_draw_line(x_prev, y_prev, x_first, y_first, colour, 1, 0);
  return 0;
}


// double fast_cos(int angle)
// {
//   // return 0;
//   // Lookup table for cosine values
  
//   // Normalize the angle to be within 0 to 360 degrees
//   // angle = angle % 360;
  
//   // Convert the angle to an index in the lookup table
//   int index = (angle / 20);
  
//   // Return the cosine value from the lookup table
//   double cos_angle = cos_table[index];

//   // for(int i = 0; i < 100000; i++)
//   // {
//   //   __NOP();
//   //   // asm("nop");
//   // }
//   return cos_angle;
// }

// double fast_sin(int angle)
// {
//   // Lookup table for sine values

//   // Normalize the angle to be within 0 to 360 degrees
//   // angle %= 360;
//   // Convert the angle to an index in the lookup table
//   int index = (angle / 20);
  
//   // Return the cosine value from the lookup table
//   double sin_angle = 
//   return sin_angle;
// }

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
  return 0;
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