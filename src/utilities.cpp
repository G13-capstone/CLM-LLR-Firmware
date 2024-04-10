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
    int result = 0; 
    // Iterate through all characters of the input string
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') { // If current character is not a number, return 0
            return 0;
        }
        result = result * 10 + str[i] - '0'; // Accumulate the result by adding the current digit
    }
    return result; // Return the result when end of string is reached
}

unsigned short intToHalfFloat(int intValue) {
     unsigned short result = 0;

    // Handle the sign
    if (intValue < 0) {
        result |= 1 << 15; // Set the sign bit
        intValue = -intValue;     
    }

    if (intValue == 0) {
        return result; 
    }

    // Find the position of the most significant bit
    int msbPos = 0;
    for (int i = 15; i >= 0; --i) {
        if (intValue & (1 << i)) {
            msbPos = i;
            break;
        }
    }

    // Calculate exponent and mantissa
    int exponent = msbPos + 15; // Adding bias, which is 15
    if (exponent > 31) {
        // Overflow, set to infinity
        result |= 0x7C00; // Exponent all ones, mantissa zero (infinity)
        return result;
    }

    // Set the exponent
    result |= ((exponent & 0x1F) << 10); // The second to the 6th bit

    // Set the mantissa
    int mantissa = (intValue & ~(1 << msbPos)) << (10 - msbPos); // The 7th to the 16th bit
    result |= (mantissa >> (msbPos - (exponent - 15)));

    return result;
}


int halfFloatToInt(unsigned short half) {
    // Extract sign, exponent, and mantissa
    bool sign = (half & 0x8000) >> 15; // first bit
    int exponent = (half & 0x7C00) >> 10; // second bit to the 6th bit
    int mantissa = half & 0x03FF; // 7th bit to 16th bit

    // Check for zero 
    if (exponent == 0 && mantissa == 0) {
        return 0;
    }

    // Normalize the mantissa
    mantissa |= 0x0400; // Add the implicit leading 1 for normalized numbers

    // Remove the bias, which is 15 and the implicit bit 1
    exponent -= (15 + 1);

    int result = mantissa;

    if (exponent > 0) {
        // Positive exponent: scale up the mantissa
        result <<= exponent;
    } else if (exponent < 0) {
        // Negative exponent: scale down the mantissa
        result >>= -exponent;
    }

    // Apply the sign
    if (sign) {
        result = -result;
    }

    return result;
}



