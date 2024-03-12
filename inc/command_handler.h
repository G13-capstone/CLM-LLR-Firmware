#ifndef __COMMAND_HANDLER_H__
#define __COMMAND_HANDLER_H__

#define MAX_COMMAND_LENGTH 30 // in characters
#define MAX_ARGUMENTS 5
#define MAX_ARGUMENT_LENGTH 30 // in characters
#define MAX_INPUT_TOKENS (1 + MAX_ARGUMENTS)

int print_test(void);

class CommandHandler {
    private:
        bool CLI_printed = false;
        bool input_entered = true; // flag used for dev/debug
        void print_CLI(void);
    public:
        void get_input(void);
        void handle_command(void);
};

#endif // __COMMAND_HANDLER_H__
