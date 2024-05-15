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

#define ARIAL         352
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
  /*Variable*/
	const uint8_t  *pfont;
	const uint16_t *pdescript;
  const unsigned long fontname_hash = hash(*fontname);
  uint16_t symbol_nr, symbol_width = 0, symbol_width_pixels, symbol_start, symbol_height; // used for searching the descriptor
  int a = 0;
  int i = 0, x, y;
  uint8_t temp, bitmask, bit;

  switch(fontname_hash)
  {
    case ARIAL:
      switch(fontstyle) 
        {
          case ITALIC:
            switch(fontsize)
            {
              case LARGE:
                a = 10;
                pfont = arial_italic_11ptBitmaps;
                pdescript = arial_italic_11ptDescriptors[0];
                symbol_height = ARIAL_LARGE_ITALIC_HEIGHT;    /* font height in pixels */
                break;
              default: // SMALL
                a = 11;
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
                pfont = arial_bold_8ptBitmaps;
                pdescript = arial_8ptDescriptors[0];
                symbol_height = ARIAL_SMALL_HEIGHT; 	/* font height in pixels */
                break;
            }
            break;
        }
    default:
      for(i=0;i<strlen(text)+1;i++)
      {
        symbol_nr = (*(text+i)) - ASCII_OFFSET;/* determines which symbol from the font library should be selected */
      }
  }
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