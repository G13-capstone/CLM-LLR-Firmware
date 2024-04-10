#include "utilities.h"
#include "io.h"
#include "uart_io.h"

/*

*/


using namespace LCD_Functions;
using L = LCD_STARTUP<DisplaySettings::DISPLAY_ON, CursorSettings::CURSOR_ON, CursorBlink::BLINK_OFF, Cursor_Line::LCD_HOME_L1>;

extern L lcd_io_driver

void charToIntTest() {
    
    if (charToInt('0') != 0) {
        puts(lcd_io_driver, "charToInt test 1 fail\n");
    }

    if (charToInt('9') != 9) {
        puts(lcd_io_driver, "charToInt test 2 fail\n");
    }

    // wrong input
    // if (charToInt('a') != 'a') {
    //     puts(lcd_io_driver, "charToInt test 3 fail\n");
    // }
}

void intToCharTest() {

    if (intToChar(1) != '1') {
        puts(lcd_io_driver, "intToChar test 1 fail\n");
    }

    if (intToChar(9) != '9') {
        puts(lcd_io_driver, "intToChar test 2 fail\n");
    }

    // Wrong data input type test
    // if (intToChar('1') != '1') {
    //     puts(lcd_io_driver, "intToChar test 3 fail\n");
    // }
}

void byteToIntTest() {

    if (byteToInt(255) != 255) {
        puts(lcd_io_driver, "byteToInt test 1 fail\n");
    }

    if (byteToInt(0) != 0) {
        puts(lcd_io_driver, "byteToInt test 2 fail\n");
    }

    // Wrong data input type test
    // if (byteToInt(-2) != 2) {
    //     puts(lcd_io_driver, "byteToInt test 3 fail\n");
    // }
}

void intToByteTest() {

    if (intToByte(0) != 0) {
        puts(lcd_io_driver, "intToByte test 1 fail\n");
    }

    if (intToByte(255) != 255) {
        puts(lcd_io_driver, "intToByte test 2 fail\n");
    }

    // if (intToByte(-10) != 10) {
    //     puts(lcd_io_driver, "intToByte test 3 fail\n");
    // }
}

void charToByteTest() {
    if (charToByte('0') != 0) {
        puts(lcd_io_driver, "charToByte test 1 fail\n");
    }

    if (charToByte('255') != 255) {
        puts(lcd_io_driver, "charToByte test 2 fail\n");
    }
    
    // if (charToByte('-1') != 255) {
    //     puts(lcd_io_driver, "charToByte test 3 fail\n");
    // }
}

void byteToCharTest() {
    if (byteToChar(0) != '0') {
        puts(lcd_io_driver, "byteToChar test 1 fail\n");
    }

    if (byteToChar(9) != '9') {
        puts(lcd_io_driver, "byteToChar test 2 fail\n");
    }
    
    // if (byteToChar(10) != 255) {
    //     puts(lcd_io_driver, "byteToChar test 3 fail\n");
    // }

    // if (byteToChar(-5) != 255) {
    //     puts(lcd_io_driver, "byteToChar test 4 fail\n");
    // }
}

void signedToUnsignedTest() {
    if (signedToUnsigned(-1) != 65536) {
        puts(lcd_io_driver, "signedToUnsigned test 1 fail\n");
    }

    if (signedToUnsigned(-32768) != 32768) {
        puts(lcd_io_driver, "signedToUnsigned test 2 fail\n");
    }

    if (signedToUnsigned(32767) != 32767) {
        puts(lcd_io_driver, "signedToUnsigned test 3 fail\n");
    }
    
    // if (signedToUnsigned(10) != 255) {
    //     puts(lcd_io_driver, "signedToUnsigned test 4 fail\n");
    // }
}

void unsignedToSignedTest() {
    if (unsignedToSigned(0) != 0) {
        puts(lcd_io_driver, "unsignedToSigned test 1 fail\n");
    }

    if (unsignedToSigned(65535) != -1) {
        puts(lcd_io_driver, "unsignedToSigned test 2 fail\n");
    }
}

void floatToIntTest() {
    if (floattoInt(1.5) != 1) {
        puts(lcd_io_driver, "floattoInt test 1 fail\n");
    }

    if (floattoInt(-9.8) != 9) {
        puts(lcd_io_driver, "floattoInt test 2 fail\n");
    }
    
    // if (floattoInt(32768) != -32768) {
    //     puts(lcd_io_driver, "floattoInt test 3 fail\n");
    // }
}

void intToFloatTest() {
     if (floattoInt(-4) != -4.0) {
        puts(lcd_io_driver, "floattoInt test 1 fail\n");
    }

    if (floattoInt(10) != 10.0) {
        puts(lcd_io_driver, "floattoInt test 2 fail\n");
    }
    
    // if (floattoInt(32768) != -32768) {
    //     puts(lcd_io_driver, "floattoInt test 3 fail\n");
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


int main() {
    L lcd_io_driver;

    puts(lcd_io_driver, "Running tests...\n\n\r");

    
    charToIntTest();
    intToCharTest();

    byteToIntTest();
    intToByteTest();

    charToByteTest();
    byteToCharTest();

    signedToUnsignedTest();
    unsignedToSignedTest();

    floatToIntTest();
    intToFloatTest();

    floatToStringTest();
    stringToFloatTest();

    intToStringTest();
    stringToIntTest();

    puts(lcd_io_driver, "\n\n\rTests Complete.\n\r");

}