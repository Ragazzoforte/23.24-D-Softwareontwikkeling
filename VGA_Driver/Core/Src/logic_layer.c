#include "main.h"
#include "logic_layer.h"

// int IO_draw_text(uint16_t x, uint16_t y, int color, char* text, char* font, int font_size, int font_style)
// {
//     /*Variable*/
// 	const uint8_t  *pbitmap;
// 	const uint16_t *pdescript;
// 	// uint8_t font_temp;
// 	// uint8_t temp;
// 	// uint8_t bitmask;
// 	// uint8_t bit;
// 	// uint16_t symbol_width = 0, symbol_width_pixels, symbol_height;
// 	// int x, y;
// 	// int i = 0;
// 	// uint16_t symbol_nr; // used for searching the descriptor
// 	// uint16_t symbol_start;

	// printf("x positie = %d\n",x);
	// printf("y positie = %d\n",y);
	// printf("color = %d\n",color);
	// printf("text = %s\n",text);
	// printf("font = %s\n",font);
	// printf("font_size = %d\n",font_size);
	// printf("font_style = %d\n",font_style);

// 	if (font == "arial")
// 	{
// 		switch(font_style) 
// 		{
// 			case ITALIC:
// 				if (font_size == LARGE)
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = arial_italic_11ptBitmaps;
// 					pdescript = arial_italic_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = arial_italic_8ptBitmaps;
// 					pdescript = arial_italic_8ptDescriptors[0];
// 				}					
// 				break;

// 			case BOLD:
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = arial_bold_11ptBitmaps;
// 					pdescript = arial_bold_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = arial_bold_8ptBitmaps;
// 					pdescript = arial_bold_8ptDescriptors[0];
// 				}	
// 				break;

// 			default: // NORMAL
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = arial_11ptBitmaps;
// 					pdescript = arial_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = arial_8ptBitmaps;
// 					pdescript = arial_8ptDescriptors[0];
// 				}	
// 				break;
// 		}
// 	}
// 	else // font == "consolas"
// 	{
// 		switch(font_style) 
// 		{
// 			case ITALIC:
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = consolas_italic_11ptBitmaps;
// 					pdescript = consolas_italic_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = consolas_italic_8ptBitmaps;
// 					pdescript = consolas_italic_8ptDescriptors[0];
// 				}						
// 				break;

// 			case BOLD:
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = consolas_bold_11ptBitmaps;
// 					pdescript = consolas_bold_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = consolas_bold_8ptBitmaps;
// 					pdescript = consolas_bold_8ptDescriptors[0];
// 				}		
// 				break;

// 			default: // NORMAL
// 				if (font_size == LARGE)
// 				{
// 					pbitmap = consolas_11ptBitmaps;
// 					pdescript = consolas_11ptDescriptors[0];
// 				}
// 				else //(font_size == SMALL)
// 				{
// 					pbitmap = consolas_8ptBitmaps;
// 					pdescript = consolas_8ptDescriptors[0];
// 				}	
// 				break;

// 		}	
// 	}

// 	printf("pbitmap = %i\n",pbitmap);
// 	printf("pdescript = %i\n",pdescript);

// // 	for(i=0;i<strlen(text);i++)
// // 		{
// // 			symbol_nr = (*(text+i)) - ASCII_OFFSET;/* determines which symbol from the font library should be selected */
// // 			// if statement voor als symbol_nr negatief
// // 			printf("symbol_nr = %d\n",symbol_nr);
// // 			printf("pdescript = %i, %i \n",pdescript, consolas_11ptDescriptors);
// // 			printf("symbol_nr * array dimension = %i\n",symbol_nr * ARRAY_DIMENSION);
// // 			printf("symbol_nr * array dimension = %i\n",*(pdescript + 168));


// // 			symbol_width_pixels = *(pdescript + symbol_nr * ARRAY_DIMENSION); /* retrieves the symbol width expressed in pixels */

// // //			printf("symbol_width_pixels = %d\n",symbol_width_pixels);
// // 			symbol_start = *(pdescript + symbol_nr * ARRAY_DIMENSION + CHAR_START_OFFSET); /* retrieves the starting elecment in the font bitmap */

// // //			printf("symbol_width = %d\n",symbol_width);

// // 			/* determines how many bytes are used in width per character */
// // 			symbol_width =  symbol_width_pixels/BYTE_SIZE;
// // 			if (symbol_width_pixels % BYTE_SIZE != 0) //voor het aantal bytes
// // 				symbol_width++;
// // 			/*
// // 			 *  Hier moet een if statement die zegt dat hij naar de volgende regel mag
// // 			 */

// // 			for(y=0; y<symbol_height;y++)//puttting symbol on screen
// // 			{
// // 				for(x=0; x<symbol_width;x++)//puttting symbol on screen
// // 				{
// // 					temp = 	*(pbitmap + symbol_start + y*symbol_width + x);

// // 					bitmask = BITMASK ;// B1000 0000
// // 					for(bit = 0; bit<BYTE_SIZE; bit++) //check per byte
// // 					{

// // 						if((temp & bitmask)!=0)
// // 						{
// // 							UB_VGA_SetPixel(x + bit + x*BYTE_SIZE , y + y, 255);
// // 						}
// // 						else
// // 						{

// // 						}

// // 						bitmask = bitmask >> 1; //define ipv 1 ??
// // 					}
// // 				}
// // 			}
// // //			printf("new character\n");
// // 			x = x + symbol_width_pixels + 1;// 1 pixel offset for spacing between symbols
// // 			//check voor out of bounds
// // 		}

// }


