#ifndef _IO_H_
#define _IO_H_
/* Interface for generic IO drivers */
class IO {
public:
	virtual void write_byte(char) = 0;
	virtual int read_byte() = 0;
};
#endif // _IO_H_
