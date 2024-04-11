#ifndef COMMAND_LIB
#define COMMAND_LIB

#include "io.h"

// void search_command(const char* command, const char* args);
void search_command( char* command, char *args[], IO &outputStream);

#endif