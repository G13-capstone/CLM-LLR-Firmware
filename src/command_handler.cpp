#include <XPD.h>
#include "command_handler.h"
#include "command_library.h"
#include "main.h"
#include "io.h"

// bool compare_string(char *str1, char *str2) {
//     int i = 0;
//     while (true) {
//         if (str1[i] == '\0' && str2[i] == '\0') {
//             return true;
//         } else if (str1[i] != str2[i]) {
//             return false;
//         }
//         i++;
//     }
// }

// Prints "UAOS CLI: " if it wasn't printed before
void CommandHandler::print_CLI(IO &outputStream) {
    if (!CLI_printed) {
        puts(outputStream, "\rUAOS CLI: ");
        CLI_printed = true;
    }
}

// Gets input from the MinGW terminal via the XPD
void CommandHandler::get_input(IO &inputStream, IO &outputStream) {
    // print_CLI(outputStream); // Prints on top of other output
    while (true) {
        // Get input char by char
        int c = getc(inputStream);

        // Check what input was returned
        if (c < 0) {
            // getc timed out, so explicitly flag that there's no input
            input_entered = false;
            break;
        } else if (c == '\r') {
            // \r means the end of an entered input
            input[charIndex] = '\0';
            // Flag that there's input to be processed
            input_entered = true;
            charIndex = 0;
            break;
        } else {
            // Build the input string char by char
            input[charIndex] = c;
            // Display output to required display
            putc(outputStream, input[charIndex]);
            // For next char
            charIndex++;
        }
    }
}

// Handles incoming commands
void CommandHandler::handle_command(IO &inputStream, IO &outputStream) {  
    // Get input from terminal
    get_input(inputStream, outputStream);
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

        char *command = inputTokens[0];

        // Force actual command to lowercase (not arguments)
        int l = 0;
        while (command[l] != '\0') {
            if (command[l] >= 'A' && command[l] <= 'Z') {
                command[l] += 32;
            }
            l++;
        }

        // convert inputToken arguments to char array
        char* arguments[MAX_INPUT_TOKENS+1];

        for (int z=1; z<j+1;z++) {
            arguments[z-1] = inputTokens[z];
        }

        arguments[j] = "\0";
        
        // Validate command by trying to find it in the command library
            // Call function with switch statement
            // If function found, execute it

            search_command(command, arguments ,outputStream);
            
            // Debug for command recognition
            // if (compare_string(command, "touch")) {
            //     putc(outputStream, '\n');
            //     puts(outputStream, inputTokens[1]);
            //     puts(outputStream, " created.\n");
            // } else {
            //     puts(outputStream, "\n\"");
            //     puts(outputStream, command);
            //     puts(outputStream, "\" not found!\n");
            // }

                // If there's an error during execution, print error

            // If function not found, print not found

        // Reset flags
        CLI_printed = false;
        input_entered = false;

        // Debug - Show what loop the command is processed on
        // xpd_puts("Command processed on loop: ");
        // xpd_echo_int(loop_counter, XPD_Flag_SignedDecimal);
        // xpd_puts("\n");
    } 
    // If there's no entered command, do nothing
    
}