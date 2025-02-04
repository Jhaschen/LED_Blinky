#define F_CPU 16000000
#define _AVR_ATmega32_


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define delay 75

void uart_init()
{
  // 8 Zeichenbits
  UCSRC |= (0 << UCSZ2) | (1 << UCSZ1) | (1<< UCSZ0);
  // 1 Stopp Bit
  UCSRC |= (0 << USBS);
  // keine Paritätsbits
  UCSRC |= (0 << UPM1) | (0<< UPM0);
  
  // Einstellen der Bitrate 9600 Baud
  // Aus Datenblatt UBRR =103
  UBRRL= 103 % 256; // Liefert 103 % 256 = 103 Rest
  UBRRH= 103/256 ; // Liefert 103/256 = O


  // Freigabe TX / RX Register
  UCSRB |= (1<< TXEN) | (1<<RXEN);

}


void uart_putc( unsigned char data ) {


/* Wait for empty transmit buffer */
 while ( !( UCSRA & (1<<UDRE)) );

/* Put data into buffer, sends the data */ 
UDR = data;

}




int main(void) {

DDRC=0b11111111; // PORTC als Ausgang einstellen

PORTC= 0xFF;

uart_init();

while (1) {
 
uart_putc('F') ; 
uart_putc('7') ; 
uart_putc('3') ; 
}

return 0;
}
