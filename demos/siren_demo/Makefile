# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: go.elf 

#additional rules for files
go.elf: ${COMMON_OBJECTS} buzzer.o stateMachines.o wdInterruptHandler.o p2_interrupt_handler.o led.o switches.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: go.elf
	msp430loader.sh go.elf

clean:
	rm -f *.o *.elf

