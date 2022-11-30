MCU=atmega328p
F_CPU= 16000000UL
CC= avr-gcc
OBJCOPY= avr-objcopy
CFFLAGS= -std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
PORT= /dev/ttyUSB0
TARGET= main
SRCS= *.c

BAUD= 115200 

PROGRAMMER= arduino

.PHONY: default
default: compile link flash clean 

.PHONY: compile
compile:
					${CC} ${CFFLAGS} -o ${TARGET}.o ${SRCS}
					${CC} ${CFFFLAGS} -o ${TARGET}.elf ${TARGET}.o

.PHONY: link
link:
					${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.elf ${TARGET}.hex
					avr-size --format=avr --mcu=${MCU}   ${TARGET}.elf

.PHONY: flash
flash:
					avrdude -v -p ${MCU} -c ${PROGRAMMER} -U  flash:w:${TARGET}.hex:i -F -P ${PORT} -b ${BAUD}

.PHONY: clean
clean:
					rm -f *.bin *.hex *.o *.elf


