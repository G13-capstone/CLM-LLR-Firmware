#ifndef _UART_IO_H_
#define _UART_IO_H_

#include <Structs.h>
#include "io.h"

class Uart_IO : public IO {
public:
	enum UART_BAUD {
		BAUD_9600,
		BAUD_115200
	};

	Uart_IO(GPIO_port_name tx_port, int tx_pin, GPIO_port_name rx_port,
		int rx_pin, enum UART_BAUD baudrate);
	void write_byte(char) override;
	int read_byte() override;

private:
	GPIO_port_name tx_port;
	int tx_pin;
	GPIO_port_name rx_port;
	int rx_pin;
	int periodTicks;
	
	uint16_t calculatePeriodTicks(UART_BAUD baudrate);
	void setup_gpio_pins(void);
};
#endif // _UART_IO_H_
