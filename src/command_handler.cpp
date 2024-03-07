// #include <SystemClock.h>
#include <XPD.h>
// #include <GPIO.h>
#include <string.h> // for strtok
#include <cctype> // For tolower()
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
        xpd_puts("UAOS CLI: ScRatCh test.py");
        CLI_printed = true;
    }
}

// Handles incoming commands
void CommandHandler::handle_command(void) {
    // Doesn't print if it's already in the terminal
    print_CLI();

    // Check terminal for entered command
    if (input_entered) {
        // If there's an entered command, then handle it
        // Get command (hardcode command for now)
        char input[MAX_COMMAND_LENGTH] = "ScRatCh test.py";
        
        // Parse commands into tokens (for arguments)
        // char * inputToken = strtok(input, " "); // TODO: strtok() and tolower() aren't supported by XInC2 assembly, replace them
        char * inputTokens[MAX_INPUT_TOKENS];
        // int i = 0;
        // while (inputToken != NULL) {
        //     inputTokens[i] = inputToken;
        //     inputToken = strtok(NULL, " ");
        //     i++;
        // }

        // Debug, may or may not print properly
        xpd_puts("Input read: ");
        xpd_puts(inputTokens[0]);
        xpd_puts(inputTokens[1]);
        xpd_puts("\n");

        // Force actual command to lowercase (not arguments)
        // char *commandName = inputTokens[0];
        // for (int j = 0; j < strlen(commandName); j++) {
        //     commandName[j] = tolower(commandName[j]);
        // }

        // Debug, may or may not print properly
        xpd_puts("Input forced to lowercase: ");
        xpd_puts(inputTokens[0]);
        xpd_puts(inputTokens[1]);
        xpd_puts("\n");
        
        // Validate command by trying to find it in the command library

            // If function found, execute it

                // If there's an error during execution, print error

            // If function not found, print not found

    } 
    // If there's no entered command, do nothing

    // Debug. Run handle_command only once
    input_entered = false;
}