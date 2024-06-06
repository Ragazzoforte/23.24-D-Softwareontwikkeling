/*
 * logic_layer.c
 *
 *  Created on: 8 mei 2024
 *      Author: Michel Vollmuller
 * 
 * functions: 
 *      - kiezen
 */

#include "main.h"

/**
 * @brief Verwerkt een commando en roept de bijbehorende API-functie aan.
 * 
 * Deze functie neemt een commando-string als invoer, bepaalt welke functie moet worden aangeroepen op basis van de hashwaarde van het eerste argument,
 * en roept de juiste API-functie aan met de gegeven argumenten.
 * 
 * @param str De commando-string die moet worden verwerkt.
 * @return none
 */

void kiezen(command str)
{
	unsigned long functie = hash(str.arg[0]);

	switch (functie)
	{
		case lijn:
            API_draw_line (atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[4]), color_chooser(str.arg[5]), atoi(str.arg[6]), atoi(str.arg[7]));
			break;
		
        case rechthoek:
            API_draw_rectangle (atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[4]), color_chooser(str.arg[5]), atoi(str.arg[6]), atoi(str.arg[7]), atoi(str.arg[8]));
			break;

        case tekst:
            API_draw_text (atoi(str.arg[1]), atoi(str.arg[2]), color_chooser(str.arg[3]), str.arg[4], str.arg[5], atoi(str.arg[6]), hash(str.arg[7]), atoi(str.arg[8]));
			break;
        
        case bitmap:
            API_draw_bitmap (atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[1]));
            break;
        
        case clearscherm:
            API_clearscreen (color_chooser(str.arg[1]));
            break;
        
        case wacht:
            UART_SendString("command not available yet. Try another function.");
            break;  
        
        case herhaal:
            UART_SendString("command not available yet. Try another function.");
            break;
        
        case cirkel:
            API_draw_polygon(atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), 70, color_chooser(str.arg[4]), 0);
            break;  
        
        case figuur:
            UART_SendString("command not available yet. Try another function.");
            break;

        case polygon:
            API_draw_polygon (atoi(str.arg[1]), atoi(str.arg[2]), atoi(str.arg[3]), atoi(str.arg[4]), color_chooser(str.arg[5]), 0);
            break;

		default:
            UART_SendString("command not found. Try again.");
			break;
	}
}