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
        xpd_puts("\nUAOS CLI: ScRatCh test.py arg2 arg3 arg4");
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
        char input[MAX_COMMAND_LENGTH + MAX_ARGUMENT_LENGTH * MAX_ARGUMENTS] = "ScRatCh test.py arg2 arg3 arg4";
        
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
        // char *argument = inputTokens[1];
        xpd_puts("Command: ");
        xpd_puts(command);
        xpd_puts("\n");
        // xpd_puts("Argument: ");
        // xpd_puts(argument);
        // xpd_puts("\n");

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

            // If function found, execute it

                // If there's an error during execution, print error

            // If function not found, print not found

    } 
    // If there's no entered command, do nothing

    // Debug. Run handle_command only once
    input_entered = false;
}