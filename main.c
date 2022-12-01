#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "Serial.h" 


int main(void){
 
  SerialInit();
  while(1){
    serialWriteLn("Bok ja sam Leo.");
    _delay_ms(100);
  }
return 0;
}


