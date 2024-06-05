#include "main.h"
#include "user_interface.h"

/**
 * @file user_interface.c
 * @brief This file contains the implementation of the user interface functions.
 */

/**
 * @brief Converts a string to a function name.
 * This function takes a string as input and returns the separated strings
 * The string is tokenized using the comma (',') delimiter.
 * 
 * @param str The input string.
 * @return a struct with the strings
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