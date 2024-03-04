// #include <SystemClock.h>
#include <XPD.h>
// #include <GPIO.h>
// #include <Thread.h>

// #include "main.h"
// #include 'command_handler.h" // ???

// Test function to check if external functions can be used from main
int print_test(void) {
    xpd_puts("Test!\n");

    return 0;
}
