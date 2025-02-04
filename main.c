#define F_CPU 16000000
#define _AVR_ATmega32_


#include <avr/io.h>
#include <util/delay.h>

#define delay 75

int main(void) {

DDRC=0b11111111; // PORTC als Ausgang einstellen

uint8_t i;
while (1) {
 
  for ( i = 0; i <=7; i++)
  {
    
    PORTC = ~(1<<i); //
    _delay_ms(delay);
  }
  for ( i = 6; i >0; i--)
  {
   
    PORTC = ~(1<<i); //
    _delay_ms(delay);
  }
 }

return 0;
}
