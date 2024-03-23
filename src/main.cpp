#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "main.h"
#include "uart_io.h"

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

char getc(IO &io) {
  return io.read_byte();
}

// main() runs in thread 0
int main(void)
{
  // Loop, printing Hello, World as well as a number, which increments every loop
  // Serves as the basic UAOS, which will eventually carry out any intended features
  //uint16_t count = 0;
  Uart_IO uart_io_driver = Uart_IO::Uart_IO(GPIO_C, 6, GPIO_C, 7, Uart_IO::BAUD_9600);
  puts(uart_io_driver, "Hello\r\n");
  while (true) {
    char c =  getc(uart_io_driver);
    if ('a' <= c && c <= 'z') {
      c = 'A' + c - 'a';
    } else if ('A' <= c && c <= 'Z') {
      c = 'a' + c - 'A';
    }
    putc(uart_io_driver, c);
    puts(uart_io_driver, "\r\n");
  }

  return 0;
}
