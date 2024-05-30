#include "main.h"
#include "user_interface.h"

/**
 * @file user_interface.c
 * @brief This file contains the implementation of the user interface functions.
 */

/**
 * @brief Converts a string to a function name.
 * This function takes a string as input and returns the first word of the string.
 * The string is tokenized using the comma (',') delimiter.
 * 
 * @param str The input string.
 * @return The first word of the string.
 */
command UI_string_to_function(char* str)
{
    command newCommand;
    newCommand.arg[0] = str;
    uint8_t i=1, j=1;
    while(*str != '\0')
    {   
        if(*str == ',')
        {
            *str = '\0';
            char *temp = str+1;
            while(*temp == 32)
            {
                temp++;
                j++;
            }
            newCommand.arg[i] = str+j;
            j=1;
            i++;
        }
        if(*str == '\n' | *str == '\r')
        {
            *str = '\0';
        }
        str++;
    }
    return newCommand; // Return the first token
}