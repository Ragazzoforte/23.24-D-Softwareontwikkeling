#include "main.h"

int kiezen(command str)
{
	unsigned long functie = hash(str.arg[0]);

	switch (functie)
	{
		case lijn:
            API_draw_line (atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[4]), color_chooser(str.arg[5]), atoi(str.arg[6]), atoi(str.arg[7]));
			return 1;
			// break;
		
        case rechthoek:
            API_draw_rectangle (atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[4]), color_chooser(str.arg[5]), atoi(str.arg[6]), atoi(str.arg[7]), atoi(str.arg[8]));
			return 2;
			// break;

        case tekst:
            API_draw_text (atoi(str.arg[1]), atoi(str.arg[2]), color_chooser(str.arg[3]), str.arg[4], str.arg[5], atoi(str.arg[6]), hash(str.arg[7]), atoi(str.arg[8]));
			return 3;
			// break;
        
        case bitmap:
            API_draw_bitmap (atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[1]));
            return 4;
            // break;
        
        case clearscherm:
            API_clearscreen (color_chooser(str.arg[1]));
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