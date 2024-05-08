#include "main.h"
#include "logic_layer.h"

int IO_draw_text(uint16_t x, uint16_t y, int color, char* text, char* font, int font_size, int font_style)
{
    /*Variable*/
	const uint8_t  *pbitmap;
	const uint16_t *pdescript;

	if (font == "arial")
	{
		switch(font_style) 
		{
			case ITALIC:
				if (font_size == LARGE)
				if (font_size == LARGE)
				{
					pbitmap = arial_italic_11ptBitmaps;
					pdescript = arial_italic_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = arial_italic_8ptBitmaps;
					pdescript = arial_italic_8ptDescriptors[0];
				}					
				break;

			case BOLD:
				if (font_size == LARGE)
				{
					pbitmap = arial_bold_11ptBitmaps;
					pdescript = arial_bold_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = arial_bold_8ptBitmaps;
					pdescript = arial_bold_8ptDescriptors[0];
				}	
				break;

			default: // NORMAL
				if (font_size == LARGE)
				{
					pbitmap = arial_11ptBitmaps;
					pdescript = arial_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = arial_8ptBitmaps;
					pdescript = arial_8ptDescriptors[0];
				}	
				break;
		}
	}
	else // font == "consolas"
	{
		switch(font_style) 
		{
			case ITALIC:
				if (font_size == LARGE)
				{
					pbitmap = consolas_italic_11ptBitmaps;
					pdescript = consolas_italic_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = consolas_italic_8ptBitmaps;
					pdescript = consolas_italic_8ptDescriptors[0];
				}						
				break;

			case BOLD:
				if (font_size == LARGE)
				{
					pbitmap = consolas_bold_11ptBitmaps;
					pdescript = consolas_bold_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = consolas_bold_8ptBitmaps;
					pdescript = consolas_bold_8ptDescriptors[0];
				}		
				break;

			default: // NORMAL
				if (font_size == LARGE)
				{
					pbitmap = consolas_11ptBitmaps;
					pdescript = consolas_11ptDescriptors[0];
				}
				else //(font_size == SMALL)
				{
					pbitmap = consolas_8ptBitmaps;
					pdescript = consolas_8ptDescriptors[0];
				}	
				break;

		}	
	}
}

