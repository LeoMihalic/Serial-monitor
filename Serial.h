//Defined constants
#pragma once

#define F_CPU 16000000UL
#define BAUD 9600 
#define BRC ((F_CPU/16/BAUD)-1)
#define TX_BUFFER_SIZE 256 

char serialBuffer[TX_BUFFER_SIZE];

void serialInit();
void appendSerial(char c);
void serialWrite(char c[]);
void serialWriteLn(char c[]);

