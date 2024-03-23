#include <Structs.h>
#include "io.h"

class Uart_IO : public IO {
public:
	enum UART_BAUD {
		BAUD_115200
	};

	Uart_IO(GPIO_port_name tx_port, int tx_pin, enum UART_BAUD baudrate);
	void write_byte(char) override;

private:
	GPIO_port_name tx_port;
	int tx_pin;
	int periodTicks;
	
	uint16_t calculatePeriodTicks(UART_BAUD baudrate);
	void setup_gpio_pins(void);
};
