#include "main.h"

int kiezen(char* str[], int size)
{
	unsigned long functie = hash(str[0]);

	switch (functie)
	{
		case lijn:
            API_draw_line (atoi(str[1]), atoi(str[2]), atoi(str[3]), atoi(str[4]), color_chooser(str[5]), atoi(str[6]), atoi(str[7]));
			return 1;
			// break;
		
        case rechthoek:
            API_draw_rectangle (atoi(str[1]), atoi(str[2]), atoi(str[3]), atoi(str[4]), color_chooser(str[5]), atoi(str[6]), atoi(str[7]), atoi(str[8]));
			return 2;
			// break;

        case tekst:
            API_draw_text (atoi(str[1]), atoi(str[2]), color_chooser(str[3]), str[4], str[5], atoi(str[6]), atoi(str[7]), atoi(str[8]));
			return 3;
			// break;
        
        case bitmap:
            API_draw_bitmap (atoi(str[2]), atoi(str[3]), atoi(str[1]));
            return 4;
            // break;
        
        case clearscherm:
            API_clearscreen (color_chooser(str[1]));
            return 5;
            // break;
        
        case wacht:
            return 6;
            // break;  
        
        case herhaal:
            return 7;
            // break;
        
        case cirkel:
            return 8;
            // break;  
        
        case figuur:
            return 9; 
            // break;

		default:
            return 100;
			// break;
	}
}