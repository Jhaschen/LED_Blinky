#define F_CPU 16000000
#define _AVR_ATmega32_


#include <avr/io.h>
#include <util/delay.h>

#define delay 100

int main(void) {

DDRC=0b11111111; // PORTC als Ausgang einstellen


while (1) {
  /* code */
  PORTC = ~(0b00001111); // MSB Bit7 ....  LSB Bit0

  _delay_ms(delay);
  PORTC = ~(0b00000000); // MSB Bit7 ....  LSB Bit0

  _delay_ms(delay);
}


return 0;
}
