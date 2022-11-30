#include <avr/io.h>
#include <util/delay.h>



#define BAUD 115200 
#define BRC ((F_CPU/16/BAUD)-1)


int main(void){
  UBRR0H= (BRC>>8);
  UBRR0L= BRC;

  UCSR0B= (1<<TXEN0);
  UCSR0C= (1<<UCSZ01) | (1<<UCSZ00);

while(1){
   UDR0= '8';
  _delay_ms(1000); 
}
}
