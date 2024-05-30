/**
  ******************************************************************************
  * @file    vga_driver.c
  * @author  Tijmen Willems, Michel Vollmuller, Tim Wannet
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
//--------------------------------------------------------------
// Function Defines
//--------------------------------------------------------------
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

//--------------------------------------------------------------

/**
 * @brief Draws a string to the VGA screen.
 * 
 * This function draws a string to the VGA screen using the specified font, size, and style.
 * 
 * @param x_lup The x-coordinate of the left upper point where the text should start.
 * @param y_lup The y-coordinate of the left upper point where the text should start.
 * @param color The color of the text.
 * @param text The text to be drawn.
 * @param fontname The name of the font to be used. arial or consolas
 * @param fontsize The size of the font. 1 for small, 2 for big.
 * @param fontstyle The style of the font. Use the predefined constants for this. 1 for normal, 2 for italic, 3 for bold.
 * @param reserved Reserved for future use.
 * 
 * @return Returns 0 on success, non-zero error code on failure.
 */
int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname,int fontsize, int fontstyle, int reserved) // fontsize:1 small, 2 big
{
  /*Variable*/
	const uint8_t  *pfont;
	const uint16_t *pdescript;
  uint16_t symbol_nr, symbol_width_pixels, symbol_start, symbol_height; // used for searching the descriptor
  int i = 0;

  /*Choose Font library*/
  if (strcmp(fontname, "arial") == 0)
  {
    switch(fontstyle) 
      {
        case ITALIC:
          switch(fontsize)
          {
            case LARGE:
              pfont = arial_italic_11ptBitmaps;
              pdescript = arial_italic_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_ITALIC_HEIGHT;    /* font height in pixels */
              break;
            default: // SMALL
              pfont = arial_italic_8ptBitmaps;
              pdescript = arial_italic_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_ITALIC_HEIGHT;   /* font height in pixels */
              break;
          }
          break;

        case BOLD:
          switch(fontsize)
          {
            case LARGE:
              pfont = arial_bold_11ptBitmaps;
              pdescript = arial_bold_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_BOLD_HEIGHT; 	/* font height in pixels */
              break;
            default: // SMALL
              pfont = arial_bold_8ptBitmaps;
              pdescript = arial_bold_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_BOLD_HEIGHT; 	/* font height in pixels */
              break;
          }
          break;

        default: // NORMAL
          switch(fontsize)
          {
            case LARGE:
              pfont = arial_11ptBitmaps;
              pdescript = arial_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_HEIGHT;    	/* font height in pixels */
              break;
            default: // SMALL
              pfont = arial_8ptBitmaps;
              pdescript = arial_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_HEIGHT; 	/* font height in pixels */
              break;
          }
          break;
      }
  }
  if(strcmp(fontname, "consolas") == 0)
  {
    switch(fontstyle) 
      {
        case ITALIC:
          switch(fontsize)
          {
            case LARGE:
              pfont = consolas_italic_11ptBitmaps;
              pdescript = consolas_italic_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_ITALIC_HEIGHT;    /* font height in pixels */
              break;
            default: // SMALL
              pfont = consolas_italic_8ptBitmaps;
              pdescript = consolas_italic_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_ITALIC_HEIGHT;   /* font height in pixels */
              break;
          }
          break;

        case BOLD:
          switch(fontsize)
          {
            case LARGE:
              pfont = consolas_bold_11ptBitmaps;
              pdescript = consolas_bold_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_BOLD_HEIGHT; 	/* font height in pixels */
              break;
            default: // SMALL
              pfont = consolas_bold_8ptBitmaps;
              pdescript = consolas_bold_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_BOLD_HEIGHT; 	/* font height in pixels */
              break;
          }
          break;

        default: // NORMAL
          switch(fontsize)
          {
            case LARGE:
              pfont = consolas_11ptBitmaps;
              pdescript = consolas_11ptDescriptors[0];
              symbol_height = ARIAL_LARGE_HEIGHT;    	/* font height in pixels */
              break;
            default: // SMALL
              pfont = consolas_8ptBitmaps;
              pdescript = consolas_8ptDescriptors[0];
              symbol_height = ARIAL_SMALL_HEIGHT; 	/* font height in pixels */
              break;
          }
          break;
      }

  }
  /*Draw text*/
  if(pfont != NULL && pdescript != NULL)
  {
    // default:
    int opschuiven = 0;
    int index = 0;
    for(i=0;i<strlen(text);i++)
    {
      symbol_nr = text[i] - ASCII_OFFSET; // Determine the symbol index
      symbol_start = pdescript[symbol_nr * ARRAY_DIMENSION + CHAR_START_OFFSET]; // Starting element in the bitmap
      symbol_width_pixels = pdescript[symbol_nr * ARRAY_DIMENSION]; // Symbol width in pixels
      for (int y = 0; y < symbol_height; y++)
      {
        for (int x = 0; x < symbol_width_pixels; x++)
        {
          if (symbol_width_pixels <= 8)         index = symbol_start + y;     // one bit wide chars

          if (symbol_width_pixels > 8 & x <= 8) index = symbol_start + (2*y); // first half of 2 bit wide chars
          if (symbol_width_pixels > 8 & x > 8)  index = symbol_start + 1 + (2*y); // second half of 2 bit wide chars

          int bit = x % 8; // Calculate the bit position within the current byte

          int pixel = (pfont[index] >> 7-bit) & 1;// Get the value of the current pixel

          // Set the pixel color based on the value of the current pixel
          if (pixel == 1) UB_VGA_SetPixel(x_lup + x + opschuiven, y_lup + y, color);
        }
      }
      opschuiven += symbol_width_pixels+1;
    }
  }
  return 0;
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
int API_draw_polygon (int x, int y, int size, int corners, int colour, int filled)
{
  if (corners < 3) // Check if the number of corners is valid
  {
    // Handle the error here
    return -1;
  }

  int angle = 360 / corners; // Calculate the angle between each corner
  int radius = size; // Set the radius of the polygon

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
    
    // if (filled == 1) // Check if the polygon should be filled
    // {
    //   for (int j = y_prev + 1; j < y_curr; j++) // Iterate over the rows between the previous and current corner
    //   {
    //     API_draw_line(x_prev, j, x_curr, j, colour, 1, 0); // Draw a horizontal line for each row
    //   }
    // }
    
    x_prev = x_curr; // Update the previous corner's x-coordinate
    y_prev = y_curr; // Update the previous corner's y-coordinate
  }

  // Close the polygon by drawing a line from the last corner to the first one
  API_draw_line(x_prev, y_prev, x_first, y_first, colour, 1, 0);
  return 0;
}

/**
 * @brief Draws a bitmap to the VGA screen.
 * 
 * This function draws a bitmap to the VGA screen at the specified coordinates. The bitmap is selected by number
 * from a predefined list of bitmaps.
 * 
 * @param x_lup The x-coordinate of the left upper point where the bitmap should be drawn.
 * @param y_lup The y-coordinate of the left upper point where the bitmap should be drawn.
 * @param bm_nr The number of the bitmap to be drawn. This corresponds to an index in the predefined list of bitmaps.
 *           The following bitmaps are available:
 *            - 1: Smiley happy
 *            - 2: Smiley sad
 *            - 3: Arrow up
 *            - 4: Arrow right
 *            - 5: Arrow down
 *            - 6: Arrow left
 *            - 7: Megaman
 * 
 * @return Returns 0 on success, non-zero error code on failure.
 */
int API_draw_bitmap (int x_lup, int y_lup, int bm_nr)
{
	//bron: http://www.brackeen.com/vga/bitmaps.html
	const uint8_t *pbitmap;
	int img_width, img_height;
	int x, y;

  /*bitmap chooser*/
	switch(bm_nr)
	{
		case SMILEY_HAPPY:
			pbitmap    = smiley_happy;
			img_width  = SMILEY_WIDTH;
			img_height = SMILEY_HEIGHT;
			break;

		case SMILEY_SAD:
			pbitmap    = smiley_sad;
			img_width  = SMILEY_WIDTH;
			img_height = SMILEY_HEIGHT;
			break;

		case ARROW_UP:
			pbitmap    = arrow_up;
			img_width  = ARROW_UP_WIDTH;
			img_height = ARROW_UP_HEIGHT;
			break;

		case ARROW_RIGHT:
			pbitmap    = arrow_right;
			img_width  = ARROW_RIGHT_WIDTH;
			img_height = ARROW_RIGHT_HEIGHT;
			break;

		case ARROW_DOWN:
			pbitmap    = arrow_down;
			img_width  = ARROW_DOWN_WIDTH;
			img_height = ARROW_DOWN_HEIGHT;

			break;

		case ARROW_LEFT:
			pbitmap    = arrow_left;
			img_width  = ARROW_LEFT_WIDTH;
			img_height = ARROW_LEFT_HEIGHT;

			break;

		case MEGAMAN:
			pbitmap	   = megaman_2;
			img_width  = MEGAMAN_WIDTH;
			img_height = MEGAMAN_HEIGHT;
			break;

		default: break;
	}
  /*draw bitmap*/
	for(y=0; y<img_height;y++)
	{

		for(x=0; x<img_width;x++)
		{
			UB_VGA_SetPixel(x_lup + x, y_lup + y, *(pbitmap + (y*img_width) + x));
		}
	}
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