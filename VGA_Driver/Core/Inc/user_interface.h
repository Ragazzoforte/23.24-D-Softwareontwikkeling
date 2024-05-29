#ifndef user_interface_h
#define user_interface_h


typedef struct command
{
    char* arg[7];
} command;

command UI_string_to_function(char* str);



#endif /* user_interface_h */