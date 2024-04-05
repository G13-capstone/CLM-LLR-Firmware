#include <XPD.h>
#include "command_handler.h"
#include "main.h"
#include "io.h"
#include "utilities.h"

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
        
        // Validate command by trying to find it in the command library
            // Call function with switch statement
            // If function found, execute it
            
            // Debug for command recognition
            if (compare_string(command, "touch")) {
                putc(outputStream, '\r');
                puts(outputStream, inputTokens[1]);
                puts(outputStream, " created.\r");
            } else {
                puts(outputStream, "\r\"");
                puts(outputStream, command);
                puts(outputStream, "\" not found!\r");
            }

                // If there's an error during execution, print error

            // If function not found, print not found

            if (compare_string(command, "chartoint")) {
                if (j >= 2) { 
                    int intValue = charToInt(inputTokens[1][0]);
                    char intStr[12];
                    intToString(intValue, intStr);
                    puts(outputStream, intStr);
                } else {
                    puts(outputStream, "Error: Not enough arguments for chartoint\r");
                }
            
            } else if (compare_string(command, "inttochar")) {
                if (j >= 2) {
                    char charValue = intToChar(stringToInt(inputTokens[1]));
                    putc(outputStream, charValue);
                    putc(outputStream, '\r'); 
                } else {
                    puts(outputStream, "Error: Not enough arguments for inttochar\r");
                }}
            // } else if (compare_string(command, "chartobyte")) {
            //     if (j >= 2) {
            //         unsigned char byteValue = charToByte(inputTokens[1][0]);
                    
            //     } else {
            //         puts(outputStream, "Error: Not enough arguments for chartobyte\r");
            //     }
            // } else if (compare_string(command, "bytetochar")) {
            //     if (j >= 2) {
            //         char charValue = byteToChar((unsigned char)stringToInt(inputTokens[1]));
            //         putc(outputStream, charValue);
            //         putc(outputStream, '\r');
            //     } else {
            //         puts(outputStream, "Error: Not enough arguments for bytetochar\r");
            //     }
            // } else if (compare_string(command, "signedtounsigned")) {
            //     if (j >= 2) {
            //         unsigned int unsignedValue = signedToUnsigned(stringToInt(inputTokens[1]));

            //     } else {
            //         puts(outputStream, "Error: Not enough arguments for signedtounsigned\r");
            //     }
            // } else if (compare_string(command, "unsignedtosigned")) {
            //     if (j >= 2) {
            //         int intValue = unsignedToSigned((unsigned int)stringToInt(inputTokens[1]));
            //         char intStr[12];
            //         intToString(intValue, intStr);
            //         puts(outputStream, intStr);
            //     } else {
            //         puts(outputStream, "Error: Not enough arguments for unsignedtosigned\r");
            //     }
            // }


            // if (compare_string(command, "add")) {
            //     char* firstNumStr = inputTokens[1];
            //     char* secondNumStr = inputTokens[2];

            //     float firstNum = stringToFloat(firstNumStr);
            //     float secondNum = stringToFloat(secondNumStr);
            //     float result = firstNum + secondNum;

            //     char resultStr[32];
            //     floatToString(result, resultStr, 2);

            //     puts(outputStream, firstNumStr);
            
            // } else if (compare_string(command, "subtract")) {
            //     char* firstNumStr = inputTokens[1];
            //     char* secondNumStr = inputTokens[2];

            //     float firstNum = stringToFloat(firstNumStr);
            //     float secondNum = stringToFloat(secondNumStr);
            //     float result = firstNum - secondNum;

            //     char resultStr[32];
            //     floatToString(result, resultStr);

            //     puts(outputStream, resultStr);
            // } else if (compare_string(command, "multiply")) {
            //     char* firstNumStr = inputTokens[1];
            //     char* secondNumStr = inputTokens[2];

            //     float firstNum = stringToFloat(firstNumStr);
            //     float secondNum = stringToFloat(secondNumStr);
            //     float result = firstNum * secondNum;

            //     char resultStr[32];
            //     floatToString(result, resultStr);

            //     puts(outputStream, resultStr);
            // } else if (compare_string(command, "divide")) {
            //     char* firstNumStr = inputTokens[1];
            //     char* secondNumStr = inputTokens[2];

            //     float firstNum = stringToFloat(firstNumStr);
            //     float secondNum = stringToFloat(secondNumStr);
                
            //     // Handle division by zero
            //     if(secondNum == 0.0f) {
            //         puts(outputStream, "Error: Division by zero");
            //         return;
            //     }

            //     float result = firstNum / secondNum;

            //     char resultStr[32];
            //     floatToString(result, resultStr);

            //     puts(outputStream, resultStr);
            // }
                    


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