#ifndef __COMMAND_HANDLER_H__
#define __COMMAND_HANDLER_H__

int print_test(void);

class CommandHandler {
    private:
        bool CLI_printed = false;
        void print_CLI(void);
    public:
        void handle_command(void);
};

#endif // __COMMAND_HANDLER_H__
