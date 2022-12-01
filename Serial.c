#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "Serial.h"

uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;

void serialInit(){
  UBRR0H= (BRC>>8);
  UBRR0L= BRC;

  UCSR0B= (1<<TXEN0) | (1<<TXCIE0);
  UCSR0C= (1<<UCSZ01) | (1<<UCSZ00);
  
  sei(); // Enabling interrupt 
}

void appendSerial(char c){
  serialBuffer[serialWritePos]= c;
  serialWritePos++;

  if(serialWritePos >= TX_BUFFER_SIZE){
    serialWritePos = 0;
  }
}

void serialWriteLn(char c[]){
  serialWrite(c);
  serialWrite("\n\r");
}

void serialWrite(char c[]){
  for(uint8_t i=0; i < strlen(c); i++){
    appendSerial(c[i]);
  }

  if(UCSR0A & (1 << UDRE0)){
    UDR0= 0;
  }
}

ISR(USART_TX_vect){
  if(serialReadPos != serialWritePos){
    UDR0= serialBuffer[serialReadPos];
    serialReadPos++;

    if(serialReadPos >= TX_BUFFER_SIZE)
      serialReadPos++;
  }
}

