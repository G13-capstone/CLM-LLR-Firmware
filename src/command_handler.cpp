#include <XPD.h>
#include "command_handler.h"

// Prints "UAOS CLI: " if it wasn't printed before
void CommandHandler::print_CLI(void) {
    if (!CLI_printed) {
        xpd_puts("\nUAOS CLI: ");
        CLI_printed = true;
    }
}

// Gets input from the MinGW terminal via the XPD
void CommandHandler::get_input(void) {
    char c;
    int i = 0;
    char timeout = 0xFF;
    print_CLI();
    while (true) {
        // xpd_getchar_timeout() is pretty buggy...
        // c = xpd_getchar_timeout(10000); // TODO = replace "magic" num w/ macro
        c = xpd_getchar();

        if (c == timeout) {
            xpd_puts("\nTimeout!\n");
            continue;
        } else if (c == '\n') {
            input[i] = '\0';
            // Flag that there's input to be processed
            input_entered = true;
            // xpd_puts("\nbreak!\n"); // debug
            break;
        } else {
            input[i] = c;
            i++;
        }
    }
    // Debug
    // xpd_puts("Input: ");
    // xpd_puts(input);
    // xpd_putc('\n');
}

// Handles incoming commands
void CommandHandler::handle_command(void) {  
    // Get input from terminal
    get_input();
    // input_entered = true; // debug
    if (input_entered) {
        // input[0] = '\0'; // debug
        // Parse commands into tokens (for arguments)
        char inputTokens[MAX_INPUT_TOKENS][MAX_ARGUMENT_LENGTH];
        int i = 0; // For characters in input
        int j = 0; // For argument tokens
        int k = 0; // For characters of argument tokens
        while (input[i] != '\0') {
            if (input[i] == ' ') {
                inputTokens[j][k] = '\0';
                j++;
                k = 0;
            } else {
                inputTokens[j][k] = input[i];
                k++;
            }
            i++;
        }
        inputTokens[j][k] = '\0';

        // Debug, may or may not print properly
        xpd_puts("\nInput tokens: ");
        int argInd1 = 0;
        while (argInd1 <= j) {
            xpd_puts(inputTokens[argInd1]);
            xpd_puts(", ");
            argInd1++;
        }
        xpd_puts("\n");

        char *command = inputTokens[0];
        xpd_puts("Command: ");
        xpd_puts(command);
        xpd_puts("\n");

        xpd_puts("Arguments: ");
        int argInd2 = 1;
        while (argInd2 <= j) {
            xpd_puts(inputTokens[argInd2]);
            xpd_puts(", ");
            argInd2++;
        }
        xpd_puts("\n");

        // Force actual command to lowercase (not arguments)
        int l = 0;
        while (command[l] != '\0') {
            if (command[l] >= 'A' && command[l] <= 'Z') {
                command[l] += 32;
            }
            l++;
        }

        // Debug, may or may not print properly
        xpd_puts("Command forced to lowercase: ");
        xpd_puts(command);
        xpd_puts("\n");
        
        // Validate command by trying to find it in the command library
            // Call function with switch statement
            // If function found, execute it

                // If there's an error during execution, print error

            // If function not found, print not found

        // Reset flags
    } 
    // If there's no entered command, do nothing

    // Debug. Run handle_command only once
    // input_entered = false;
    CLI_printed = false;
    input_entered = false;
}