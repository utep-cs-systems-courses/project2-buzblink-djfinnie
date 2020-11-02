# Project 2- Buzzy-Blinky Toy


## Files--
1. wdInterruptHandler - handles interrupts.
2. buzzer - initialzes buzzer sets buzzer tones.
3. led - initializes leds sets bits for green led or red to be displayed.
4. p2_interrupt_handler - senses when buttons are pressed on MSP430.
5. stateMachines - contains all functions and states for the MSP430.
6. switches - Initializes switches, dectects when they are pressed.

## How to use -
1. First open the project directory by using cd
2. cd project
3. cd src
4. Then type make into the console with MSP430 plugged in
5. Then make load
6. S1 will alternate between green and red leds
7. S2 will will play a short song and flash red led on loop
8. S3 will play a constant buzzer red led and dim flashing green led
9. S4 will turn off buzzer and leds
10. Type make clean to remove temp files created on load
