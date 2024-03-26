#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "command_handler.h"
#include "uart_io.h"
#include "LCD.h"
#include "io.h"

// sys_clock_wait can only wait a maximum of 65535 ticks
// use a loop to get a longer delay.
void long_wait()
{
  for (int i = 0; i < 5000; ++i) {
    sys_clock_wait(10000);
  }
}

using namespace LCD_Functions;
using L = LCD_STARTUP<DisplaySettings::DISPLAY_ON, CursorSettings::CURSOR_ON, CursorBlink::BLINK_OFF, Cursor_Line::LCD_HOME_L1>;

// main() runs in thread 0
int main(void)
{
  // Loop, printing Hello, World as well as a number, which increments every loop
  // Serves as the basic UAOS, which will eventually carry out any intended features
  //uint16_t count = 0;
  Uart_IO uart_io_driver = Uart_IO::Uart_IO(GPIO_C, 6, GPIO_C, 7, Uart_IO::BAUD_9600);
  Uart_IO keyboard_io_driver = Uart_IO::Uart_IO(GPIO_C, 5, GPIO_C, 4, Uart_IO::BAUD_9600);
  L lcd_io_driver;

  puts(uart_io_driver, "Hello\r\n");
  puts(lcd_io_driver, "hello");

  CommandHandler commandHandler = CommandHandler();
  char input[MAX_INPUT_TOKENS * MAX_ARGUMENT_LENGTH];
  char command[MAX_COMMAND_LENGTH];
  int charInd = 0;

  while (true) {
    int c = getc(keyboard_io_driver);
    if (c >= 0) {
      // if ('a' <= c && c <= 'z') {
      //   c = 'A' + c - 'a';
      // } else
      if ('A' <= c && c <= 'Z') {
        c = 'a' + c - 'A';
      }
      // Show keyboard input on output devices
      putc(uart_io_driver, c);
      putc(lcd_io_driver, c);

      // Take input and form a string
      if (c != '\r') {
        input[charInd] = c;
        charInd++;
      } else if (c == '\r') {
        input[charInd] = '\0';
        charInd = 0;

        // Process input into tokens
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

        // Verify command
        if (compare_string(command, "touch")) {
          puts(uart_io_driver, inputTokens[1]);
          puts(uart_io_driver, " created.\n");
        } else {
          putc(uart_io_driver, '\"');
          puts(uart_io_driver, command);
          puts(uart_io_driver, "\" not found!");
        }
      }
    }
    // commandHandler.handle_command();
    commandHandler.loop_counter++;
  }

  return 0;
}
