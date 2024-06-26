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
  Uart_IO uart_io_driver = Uart_IO::Uart_IO(GPIO_C, 6, GPIO_C, 7, Uart_IO::BAUD_9600);
  Uart_IO keyboard_io_driver = Uart_IO::Uart_IO(GPIO_C, 5, GPIO_C, 4, Uart_IO::BAUD_9600);
  L lcd_io_driver;

  CommandHandler commandHandler = CommandHandler();

  while (true) {
    // commandHandler.handle_command(keyboard_io_driver, uart_io_driver); // Input keyboard, output to COM Terminal
    commandHandler.handle_command(keyboard_io_driver, lcd_io_driver); // Input keyboard, output to LCD
    // commandHandler.handle_command(uart_io_driver, uart_io_driver); // Input COM terminal, output COM terminal
    commandHandler.loop_counter++;
  }

  return 0;
}
