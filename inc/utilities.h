#ifndef UTILITIES_H
#define UTILITIES_H

// Convert Char to Int
int charToInt(char c);

// Convert Int to Char
char intToChar(int i);

// Convert Byte to Int
int byteToInt(unsigned char b);

// Convert Int to Byte
unsigned char intToByte(int i);

// Convert Char to Byte
unsigned char charToByte(char c);

// Convert Byte to Char 
char byteToChar(unsigned char b);

// Convert Signed Int to Unsigned Int
unsigned int signedToUnsigned(int i);

// Convert Unsigned Int to Signed Int
int unsignedToSigned(unsigned int i);

// Convert Int to Float
float intToFloat(int i);

// Convert Float to Int
int floatToInt(float f);

// Arithmetic operations

void intToString(int value, char *str);

int stringToInt(const char *str);

unsigned short intToHalfFloat(int intValue);

int halfFloatToInt(unsigned short halfFloat);

#endif // UTILITIES_H
