#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "command_handler.h"
#include "uart_io.h"
#include "LCD.h"
#include "io.h"
#include "utilities.h"

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

  // Debug
  // puts(uart_io_driver, "Hello\r\n");
  // puts(lcd_io_driver, "hello");

  CommandHandler commandHandler = CommandHandler();

  while (true) {
    // commandHandler.handle_command(uart_io_driver, uart_io_driver); // Display to COM Terminal
    // commandHandler.handle_command(uart_io_driver, lcd_io_driver); // Display to LCD
    // commandHandler.loop_counter++;
    // xpd_putc(byteToChar(0x41));
    xpd_echo_int(byteToInt(0x41),XPD_Flag_SignedDecimal);
  }

  return 0;
}
