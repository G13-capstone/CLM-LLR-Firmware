#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "main.h"
#include "command_handler.h"
#include "uart_io.h"
#include "LCD.h"

// sys_clock_wait can only wait a maximum of 65535 ticks
// use a loop to get a longer delay.
void long_wait()
{
  for (int i = 0; i < 5000; ++i) {
    sys_clock_wait(10000);
  }
}

void puts(IO &io, const char *c) {
  while(*c) {
    io.write_byte(*c);
    c++;
  }
}

void putc(IO &io, const char c) {
  io.write_byte(c);
}

int getc(IO &io) {
  return io.read_byte();
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

  CommandHandler commandHandler = CommandHandler();

  while (true) {
    int c = getc(keyboard_io_driver);
    if (c >= 0) {
      if ('a' <= c && c <= 'z') {
        c = 'A' + c - 'a';
      } else if ('A' <= c && c <= 'Z') {
        c = 'a' + c - 'A';
      }
      putc(uart_io_driver, c);
      putc(lcd_io_driver, c);
    }
    // command_handler.handle_command();
    // commandHandler.loop_counter++;
  }

  return 0;
}
