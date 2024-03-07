// #include <SystemClock.h>
#include <XPD.h>
// #include <GPIO.h>
#include <string>
using namespace std;

// #include "main.h"
#include "command_handler.h" // ???

// Test function to check if external functions can be used from main
int print_test(void) {
    xpd_puts("Test!\n");

    return 0;
}

// Prints "UAOS CLI: " if it wasn't printed before
void CommandHandler::print_CLI(void) {
    if (!CLI_printed) {
        xpd_puts("UAOS CLI: ");
        CLI_printed = true;
    }
}

// Handles incoming commands
void CommandHandler::handle_command(void) {
    // Doesn't print if it's already in the terminal
    print_CLI();

    // Check terminal for entered command
    
        // If there's an entered command, handle it

        // Get command

        // Pre-process and parse commands into tokens (for arguments)

        // Validate command by trying to find it in the command library

            // If function found, execute it

                // If there's an error during execution, print error

            // If funciton not found, print not found

        // If there's no entered command, do nothing

}