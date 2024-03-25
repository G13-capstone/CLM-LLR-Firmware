#include <GPIO.h>
#include <Structs.h>
#include <SystemClock.h>
#include <SXC.h>
#include <XPD.h>

#include <uart_io.h>

Uart_IO::Uart_IO(GPIO_port_name tx_port, int tx_pin, GPIO_port_name rx_port,
		int rx_pin, UART_BAUD baudrate) {
	this->tx_port = tx_port;
	this->tx_pin = tx_pin;
	this->rx_port = rx_port;
	this->rx_pin = rx_pin;
	this->periodTicks = calculatePeriodTicks(baudrate);
	setup_gpio_pins();
}

void Uart_IO::write_byte(char c) {
	// Send start bit
	uint16_t pin_mask = ~(1 << this->tx_pin);
	gpio_write(gpio_read(this->tx_port) & pin_mask, this->tx_port);
	internal_busy_wait(this->periodTicks);
	for (int i = 0; i < 8; i++) {
		uint16_t bit = (_ror(c, i) & 1);
		if (bit)
			gpio_write(gpio_read(this->tx_port) | ~pin_mask, this->tx_port);
		else
			gpio_write(gpio_read(this->tx_port) & pin_mask, this->tx_port);
		sys_clock_wait(this->periodTicks);
	}
	// Send stop bit
	gpio_write(gpio_read(this->tx_port) | ~pin_mask, this->tx_port);
	internal_busy_wait(this->periodTicks);
}

int Uart_IO::read_byte() {
	int c = 0;
	// Send start bit
	uint16_t pin_mask = 1 << this->rx_pin;
	// Poll for start bit
	uint16_t timeout = 10000;
	while ((gpio_read(this->rx_port) & pin_mask) != 0 && timeout > 0) {
		timeout--;
	}
	if (timeout == 0) {
		return -1;
	}

	// Wait for 1.5 cycles to sample during middle of first bit
	internal_busy_wait(this->periodTicks + (_ror(this->periodTicks, 1)) & 0x7fff);

	// Read in bits
	for (int i = 0; i < 8; i++) {
		uint16_t bit = _ror(gpio_read(this->rx_port), this->rx_pin) & 1;
		c |= _rol(bit, i);
		sys_clock_wait(this->periodTicks);
	}

	// Wait for stop bit
	while ((gpio_read(this->rx_port) & pin_mask) == 0);
	return c;
}

uint16_t Uart_IO::calculatePeriodTicks(enum UART_BAUD baudrate) {
	switch (baudrate) {
	case BAUD_9600:
		return 10240 - 288 + 16;
	case BAUD_115200:
		return 853 - 288 + 16; // 98.304 MHz / 115200 baud - overhead cycles
	}
}

void Uart_IO::setup_gpio_pins(void) {
	// setup tx_port as output on pin tx_pin
	uint16_t cfg = (1 << (8 + this->tx_pin)) | gpio_get_config(this->tx_port);
	gpio_set_config(cfg, this->tx_port);

	// setup rx_port as input on pin rx_pin
	cfg = ~(1 << (8 + this->rx_pin)) & gpio_get_config(this->rx_port);
	gpio_set_config(cfg, this->rx_port);
}
