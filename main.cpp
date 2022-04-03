/*
 * adamsblinkmojt1.cpp
 *
 * Created: 2022-03-25 00:23:06
 * Author : adam @ ETF
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void my_blink() {
	PORTB = 0xff;
	PORTD = 0xff;
	PORTC = 0xff;

	_delay_ms(1000);

	PORTB = 0x00;
	PORTD = 0x00;
	PORTC = 0x00;

	_delay_ms(1000);
}

int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRD = 0xFF;

	while (1) {
		for (int i = 0; i < 10; i++) {
			uint8_t my_port = 0;
			for (my_port = 1; my_port != 0b10000000; my_port = (my_port<<1)) {
				PORTC = my_port;
				PORTD = my_port;
				PORTB = my_port;
				_delay_ms(100);
			}
		}

		for (int i = 0; i < 3; i++) 
		{
			my_blink();
		}
	}
}

