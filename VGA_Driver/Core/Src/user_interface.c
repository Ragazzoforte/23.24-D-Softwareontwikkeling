#include "main.h"
#include "user_interface.h"

/**
 * @file user_interface.c
 * @author Tijmen Willems, Michel Vollmuller, Tim Wannet
 * @brief User interface Source File
 * This file contains the implementation of the user interface functions.
 *  - UI_string_to_function(): used to parce an incoming command. 
 */

/**
 * @brief Converts a string to a function name.
 * This function takes a string as input and returns the separated strings
 * The string is tokenized using the comma (',') delimiter.
 * 
 * @note You can disable the seperation of a specific comma by passing a backslash in front of that comma ('\,').
 * 
 * @param str The input string.
 * @return A struct of type 'command' with pointers to the seperated strings.
 */
command UI_string_to_function(char* str)
{
    command newCommand;
    newCommand.arg[0] = str;
    uint8_t i=1;
    while(*str != '\0')
    {   
        if((*str == ',' )&( *(str-1) != 92)) //check for comma without backslash
        {
            *str = '\0';
            uint8_t j = 1;
            while(*(str+j) == 32) j++;
            newCommand.arg[i] = str+j;
            i++;
        }
        if((*str == '\n' )|( *str == '\r'))
        {
            *str = '\0';
        }
        str++;
    }
    return newCommand; // Return the first token
}