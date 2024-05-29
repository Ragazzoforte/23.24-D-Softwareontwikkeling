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
char* UI_string_to_function(char* str)
{
    char* first_word;
    char* rest = str;

    // Get the first token
    first_word = strtok_r(rest, ",", &rest);

    return first_word; // Return the first token
}