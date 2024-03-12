#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "main.h"
#include "command_handler.h"

// sys_clock_wait can only wait a maximum of 65535 ticks
// use a loop to get a longer delay.
void long_wait()
{
  for (int i = 0; i < 5000; ++i) {
    sys_clock_wait(10000);
  }
}

// main() runs in thread 0
int main(void)
{
  // Loop, printing Hello, World as well as a number, which increments every loop
  // Serves as the basic UAOS, which will eventually carry out any intended features
  CommandHandler commandHandler = CommandHandler();
  while (true) {
    // print_test();
    // commandHandler.handle_command(); // Shouldn't print twice
    commandHandler.get_input();
    long_wait();
  }

  return 0;
}
