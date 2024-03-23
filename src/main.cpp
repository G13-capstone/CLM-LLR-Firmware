#include <SystemClock.h>
#include <XPD.h>
#include <GPIO.h>
#include <Thread.h>

#include "main.h"
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

char getc(IO &io) {
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
  puts(uart_io_driver, "Hello\r\n");
  L lcd_io_driver;

  SPI_set_config((SPI_ENABLE | SPI_MASTER | SPI_CLK_RATE_DIV_256) & ~(SPI_CLK_PHASE | SPI_CLK_IDLE_AT_1), SPI0);
  gpio_set_config(gpio_get_config(GPIO_C) | (0x0C << 8), GPIO_C); // PC3 will be used as the Reset Pin, PC2 is Chip Select
  ResetLCD();
  // Set CS and reset high
  gpio_write(gpio_get_output_reg(GPIO_C) | 0xC, GPIO_C);
  lcd_io_driver.initializeDOGM204();
  lcd_io_driver.setViewAngleTop();
  lcd_io_driver.clrDisplay();
  lcd_io_driver.setDisplayMode();
  lcd_io_driver.setCursorMode();
  lcd_io_driver.setBlinkMode();
  lcd_io_driver.setCursor(0, 0);

  while (true) {
    char c =  getc(uart_io_driver);
    if ('a' <= c && c <= 'z') {
      c = 'A' + c - 'a';
    } else if ('A' <= c && c <= 'Z') {
      c = 'a' + c - 'A';
    }
    putc(uart_io_driver, c);
    putc(lcd_io_driver, c);
  }

  return 0;
}
