#ifndef __COMMAND_HANDLER_H__
#define __COMMAND_HANDLER_H__

#define MAX_COMMAND_LENGTH 50 // in characters
#define MAX_INPUT_TOKENS 10

int print_test(void);

class CommandHandler {
    private:
        bool CLI_printed = false;
        bool input_entered = true; // flag used for dev/debug
        void print_CLI(void);
    public:
        void handle_command(void);
};

#endif // __COMMAND_HANDLER_H__
