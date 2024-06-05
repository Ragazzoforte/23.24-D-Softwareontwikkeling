/**
 * @file user_interface.h
 * @author Michel Vollmuller (michel.vollmuller@gmail.com)
 * @author Tim Wannet (tim.wannet@student.hu.nl)
 * @author Tijmen Willems (tijmen.willems@student.hu.nl)
 * @brief headerfile of user_interface.c
 * @version 0.1
 * @date 05-06-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef user_interface_h
#define user_interface_h


typedef struct command
{
    char* arg[20];
} command;

command UI_string_to_function(char* str);



#endif /* user_interface_h */