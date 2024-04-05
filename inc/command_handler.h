#ifndef __COMMAND_HANDLER_H__
#define __COMMAND_HANDLER_H__

#include "io.h"

#define MAX_COMMAND_LENGTH 30 // in characters
#define MAX_ARGUMENTS 5
#define MAX_ARGUMENT_LENGTH 30 // in characters
#define MAX_INPUT_TOKENS (1 + MAX_ARGUMENTS)

bool compare_string(char *str1, char *str2);

class CommandHandler {
    private:
        bool CLI_printed = false;
        bool input_entered = false; // flag used for dev/debug
        char input[MAX_COMMAND_LENGTH + MAX_ARGUMENT_LENGTH * MAX_ARGUMENTS] = "hello world";
        int charIndex = 0;
        void print_CLI(IO &outputStream);
        void get_input(IO &inputStream, IO &outputStream);
    public:
        void handle_command(IO &inputStream, IO &outputStream);
        int loop_counter = 0; // Debug
};

#endif // __COMMAND_HANDLER_H__
