#include <XPD.h>
#include "command_handler.h"
#include "main.h"

bool compare_string(char *str1, char *str2) {
    int i = 0;
    while (true) {
        if (str1[i] == '\0' && str2[i] == '\0') {
            return true;
        } else if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
}

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
    int timeout = -1;
    print_CLI();
    while (true) {
        // Get input char by char
        c = xpd_getchar_timeout(10000);

        // Check what input was returned
        if (c == timeout) {
            // Explicitly flag that there's no input
            input_entered = false;
            break;
        } else if (c == '\n') {
            // New line means the end of an entered input
            input[i] = '\0';
            // Flag that there's input to be processed
            input_entered = true;
            break;
        } else {
            // Build the input string char by char
            input[i] = c;
            i++;
        }
    }
}

// Handles incoming commands
void CommandHandler::handle_command(void) {  
    // Get input from terminal
    get_input();
    if (input_entered) {
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

        // Debug for token printing
        // xpd_puts("\nInput tokens: ");
        // int argInd1 = 0;
        // while (argInd1 <= j) {
        //     xpd_puts(inputTokens[argInd1]);
        //     xpd_puts(", ");
        //     argInd1++;
        // }
        // xpd_puts("\n");

        char *command = inputTokens[0];
        // Debug for command print
        // xpd_puts("Command: ");
        // xpd_puts(command);
        // xpd_puts("\n");

        // Debug print for arguments
        // xpd_puts("Arguments: ");
        // int argInd2 = 1;
        // while (argInd2 <= j) {
        //     xpd_puts(inputTokens[argInd2]);
        //     xpd_puts(", ");
        //     argInd2++;
        // }
        // xpd_puts("\n");

        // Force actual command to lowercase (not arguments)
        int l = 0;
        while (command[l] != '\0') {
            if (command[l] >= 'A' && command[l] <= 'Z') {
                command[l] += 32;
            }
            l++;
        }

        // Debug, may or may not print properly
        // xpd_puts("Command forced to lowercase: ");
        // xpd_puts(command);
        // xpd_puts("\n");
        
        // Validate command by trying to find it in the command library
            // Call function with switch statement
            // If function found, execute it
            
            // Debug for command recognition
            if (compare_string(command, "touch")) {
                xpd_puts(inputTokens[1]);
                xpd_puts(" created.\n");
            }

                // If there's an error during execution, print error

            // If function not found, print not found

        // Reset flags
        CLI_printed = false;
        input_entered = false;

        // Debug - Show what loop the command is processed on
        xpd_puts("Command processed on loop: ");
        xpd_echo_int(loop_counter, XPD_Flag_SignedDecimal);
        xpd_puts("\n");
    } 
    // If there's no entered command, do nothing
    
}