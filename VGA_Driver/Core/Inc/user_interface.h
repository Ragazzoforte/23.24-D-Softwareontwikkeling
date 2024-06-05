#ifndef user_interface_h
#define user_interface_h

/**
 * @file user_interface.h
 * @author Tijmen Willems, Michel Vollmuller, Tim Wannet
 * @brief User interface Header File
 * This file contains the declarations of the user interface functions and structs.
 */

/** 
  * @brief Seperated command
  */
typedef struct command
{
    char* arg[20];
} command;

command UI_string_to_function(char* str);



#endif /* user_interface_h */