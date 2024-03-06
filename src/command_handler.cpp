// #include <SystemClock.h>
#include <XPD.h>
// #include <GPIO.h>
// #include <Thread.h>

// #include "main.h"
#include "command_handler.h" // ???

// Test function to check if external functions can be used from main
int print_test(void) {
    xpd_puts("Test!\n");

    return 0;
}

// Prints "UAOS CLI: " if it wasn't printed before
void CommandHandler::print_CLI(void) {
    if (CLI_printed) {
        xpd_puts("UAOS CLI: ");
        CLI_printed = true;
    }
}

void CommandHandler::handle_command(void) {
    xpd_puts("debug");
    print_CLI();
    xpd_puts("debug2");
}