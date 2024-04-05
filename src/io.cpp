#include "io.h"

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