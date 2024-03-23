#include <GPIO.h>
#include <Structs.h>
#include <SystemClock.h>
#include <SXC.h>
#include <XPD.h>

#include <uart_io.h>

Uart_IO::Uart_IO(GPIO_port_name tx_port, int tx_pin, UART_BAUD baudrate) {
	this->tx_port = tx_port;
	this->tx_pin = tx_pin;
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

uint16_t Uart_IO::calculatePeriodTicks(enum UART_BAUD baudrate) {
	return 853 - 288 + 16; // 98.304 MHz / 115200 baud - overhead cycles
}

void Uart_IO::setup_gpio_pins(void) {
	// setup tx_port as output on pin tx_pin
	uint16_t cfg = (1 << (8 + this->tx_pin)) | gpio_get_config(this->tx_port);
	gpio_set_config(cfg, this->tx_port);
}
