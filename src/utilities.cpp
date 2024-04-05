#include <utilities.h>


// Convert Char to Int
int charToInt(char c) {
    return static_cast<int>(c);
}

// Convert Int to Char
char intToChar(int i) {
    return static_cast<char>(i);
}

// Convert Byte to Int
int byteToInt(unsigned char b) {
    return static_cast<int>(b);
}

// Convert Int to Byte
unsigned char intToByte(int i) {
    return static_cast<unsigned char>(i);
}

// Convert Char to Byte
unsigned char charToByte(char c) {
    return static_cast<unsigned char>(c);
}

// Convert Byte to Char 
char byteToChar(unsigned char b) {
    return static_cast<char>(b);
}


// Convert Signed Int to Unsigned Int
unsigned int signedToUnsigned(int i) {
    return static_cast<unsigned int>(i);
}

// Convert Unsigned Int to Signed Int
int unsignedToSigned(unsigned int i) {
    return static_cast<int>(i);
}

// Convert Int to Float
float intToFloat(int i) {
    return static_cast<float>(i);
}

// Convert Float to Int
int floatToInt(float f) {
    return static_cast<int>(f);
}

float stringToFloat(const char* str) {
    float result = 0.0f;
    float divisor = 1.0f;
    bool decimalPointEncountered = false;

    while (*str != '\0') {
        if (*str == '.') {
            decimalPointEncountered = true;
        } else {
            int digit = *str - '0';
            if (digit >= 0 && digit <= 9) {
                if (decimalPointEncountered) {
                    divisor *= 10.0f;
                    result += (float)digit / divisor;
                } else {
                    result = result * 10.0f + (float)digit;
                }
            } else {
                
            }
        }
        ++str;
    }

    return result;
}

void floatToString(float value, char* buffer, int decimalPlaces) {
    if (!buffer) return;
    
    // Convert the integer part to string
    int intPart = (int)value;
    int i = 0;
    do {
        buffer[i] = (char)(intPart % 10 + '0');
        i++;
        intPart /= 10;
    } while (intPart > 0);

    // // Reverse the integer part string
    // for (int j = 0; j < i / 2; ++j) {
    //     char temp = buffer[j];
    //     buffer[j] = buffer[i - j - 1];
    //     buffer[i - j - 1] = temp;
    // }

    // buffer[i++] = '.'; // Decimal point

    // // Convert the decimal part to string
    // float remainder = value - (int)value;
    // for (int dec = 0; dec < decimalPlaces; ++dec) {
    //     remainder *= 10;
    //     buffer[i++] = (char)((int)remainder % 10 + '0');
    //     remainder -= (int)remainder;
    // }

    // buffer[i] = '\0'; // Null-terminate the string
}

void intToString(int value, char* buffer) {
    if (!buffer) return;

    char* start = buffer;
    if (value < 0) {
        *buffer++ = '-';
        value = -value;
    }

    // Handle zero explicitly
    if (value == 0) {
        *buffer++ = '0';
        *buffer = '\0';
        return;
    }

    // Calculate the magnitude
    int magnitude = 1;
    while (value - magnitude * 10 >= 0) {
        magnitude *= 10;
    }

    // Construct the string backwards
    char* end = buffer;
    while (magnitude > 0) {
        int digitCount = 0;
        while (value - magnitude >= 0) {
            value -= magnitude;
            digitCount++;
        }
        *end++ = '0' + digitCount;

        // Update magnitude by dividing by 10 without using '/'
        int newMagnitude = 0;
        int tempMag = magnitude;
        while (tempMag > 9) {
            newMagnitude = newMagnitude * 10 + 10;
            tempMag -= 10;
        }
        magnitude = newMagnitude;
    }
    
    // Null-terminate the string
    *end = '\0';

    // Reverse the string for correct order, if it was negative, ignore the '-' sign
    char* revStart = (start[0] == '-') ? start + 1 : start;
    char* revEnd = end - 1;
    while (revStart < revEnd) {
        char tmp = *revStart;
        *revStart = *revEnd;
        *revEnd = tmp;
        revStart++;
        revEnd--;
    }
}


int stringToInt(const char* str) {
    if (!str) return 0; // Handle null pointer

    int num = 0;
    int sign = 1;  // Assume positive number

    // Check for negative sign
    if (*str == '-') {
        sign = -1;
        str++; // Move to the next character
    }

    // Convert string to integer
    while (*str) {
        if (*str < '0' || *str > '9') {
            break; // Stop if character is not a digit
        }

        // Multiply current number by 10 and add the new digit
        num = num * 10 + (*str - '0');

        str++; // Move to the next character
    }

    return sign * num;
}
