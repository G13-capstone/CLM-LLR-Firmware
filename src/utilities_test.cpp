#include "utilities_test.h"
#include "utilities.h"
#include "io.h"
#include "uart_io.h"

/*
Tests for utilities.cpp
*/

void charToIntTest(IO &outputStream) {
    
    if (charToInt('0') != 0) {
        puts(outputStream, "charToInt test 1 fail\n");
    }

    if (charToInt('9') != 9) {
        puts(outputStream, "charToInt test 2 fail\n");
    }

    // returns ASCII value
    if (charToInt('a') != 97) {
        puts(outputStream, "charToInt test 3 fail\n");
    }
}

void intToCharTest(IO &outputStream) {

    if (intToChar(1) != '1') {
        puts(outputStream, "intToChar test 1 fail\n");
    }

    if (intToChar(9) != '9') {
        puts(outputStream, "intToChar test 2 fail\n");
    }

    // returns ASCII value
    if (intToChar(10) != '1') {
        puts(outputStream, "intToChar test 3 fail\n");
    }
}

void byteToIntTest(IO &outputStream) {

    if (byteToInt(255) != 255) {
        puts(outputStream, "byteToInt test 1 fail\n");
    }

    if (byteToInt(0) != 0) {
        puts(outputStream, "byteToInt test 2 fail\n");
    }

    // Wrong data input type test
    // if (byteToInt(-2) != 2) {
    //     puts(outputStream, "byteToInt test 3 fail\n");
    // }
}

void intToByteTest(IO &outputStream) {

    if (intToByte(0) != 0) {
        puts(outputStream, "intToByte test 1 fail\n");
    }

    if (intToByte(255) != 255) {
        puts(outputStream, "intToByte test 2 fail\n");
    }

    // if (intToByte(-10) != 10) {
    //     puts(outputStream, "intToByte test 3 fail\n");
    // }
}

void charToByteTest(IO &outputStream) {
    if (charToByte('0') != 0) {
        puts(outputStream, "charToByte test 1 fail\n");
    }

    if (charToByte('9') != 9) {
        puts(outputStream, "charToByte test 2 fail\n");
    }
    
    // if (charToByte('-1') != 255) {
    //     puts(outputStream, "charToByte test 3 fail\n");
    // }
}

void byteToCharTest(IO &outputStream) {
    if (byteToChar(0) != '0') {
        puts(outputStream, "byteToChar test 1 fail\n");
    }

    if (byteToChar(9) != '9') {
        puts(outputStream, "byteToChar test 2 fail\n");
    }
    
    // if (byteToChar(10) != 255) {
    //     puts(outputStream, "byteToChar test 3 fail\n");
    // }

    // if (byteToChar(-5) != 255) {
    //     puts(outputStream, "byteToChar test 4 fail\n");
    // }
}

void signedToUnsignedTest(IO &outputStream) {
    if (signedToUnsigned(-1) != 65536) {
        puts(outputStream, "signedToUnsigned test 1 fail\n");
    }

    if (signedToUnsigned(-32768) != 32768) {
        puts(outputStream, "signedToUnsigned test 2 fail\n");
    }

    if (signedToUnsigned(32767) != 32767) {
        puts(outputStream, "signedToUnsigned test 3 fail\n");
    }
    
    // if (signedToUnsigned(10) != 255) {
    //     puts(outputStream, "signedToUnsigned test 4 fail\n");
    // }
}

void unsignedToSignedTest(IO &outputStream) {
    if (unsignedToSigned(0) != 0) {
        puts(outputStream, "unsignedToSigned test 1 fail\n");
    }

    if (unsignedToSigned(65535) != -1) {
        puts(outputStream, "unsignedToSigned test 2 fail\n");
    }
    
    if (unsignedToSigned(32767) != 32767) {
        puts(outputStream, "unsignedToSigned test 3 fail\n");
    }
}

void floatToIntTest(IO &outputStream) {
    if (floattoInt(1.5f) != 1) {
        puts(outputStream, "floattoInt test 1 fail\n");
    }

    if (floattoInt(-9.8f) != 9) {
        puts(outputStream, "floattoInt test 2 fail\n");
    }
    
    // if (floattoInt(32768f) != -32768) {
    //     puts(lcd_io_driver, "floattoInt test 3 fail\n");
    // }
}

void intToFloatTest(IO &outputStream) {
     if (floattoInt(-4) != -4.0f) {
        puts(outputStream, "floattoInt test 1 fail\n");
    }

    if (floattoInt(10) != 10.0f) {
        puts(outputStream, "floattoInt test 2 fail\n");
    }
    
    // if (floattoInt(32768) != -32768f) {
    //     puts(outputStream, "floattoInt test 3 fail\n");
    // }
}

void floatToStringTest() {

}

void stringToFloatTest() {

}

void intToStringTest() {

}

void stringToIntTest() {

}


void testmain(IO &outputStream) {

    puts(outputStream, "Running tests...\n\n\r");

    
    charToIntTest(outputStream);
    intToCharTest(outputStream);

    byteToIntTest(outputStream);
    intToByteTest(outputStream);

    charToByteTest(outputStream);
    byteToCharTest(outputStream);

    signedToUnsignedTest(outputStream);
    unsignedToSignedTest(outputStream);

    floatToIntTest(outputStream);
    intToFloatTest(outputStream);

    floatToStringTest();
    stringToFloatTest();

    intToStringTest();
    stringToIntTest();

    puts(outputStream, "\n\n\rTests Complete.\n\r");

}