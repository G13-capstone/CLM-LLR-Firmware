#ifndef _IO_H_
#define _IO_H_
/* Interface for generic IO drivers */
class IO {
public:
	virtual void write_byte(char) = 0;
	virtual int read_byte() = 0;
};

void puts(IO &io, const char *c);
void putc(IO &io, const char c);
int getc(IO &io);
#endif // _IO_H_
