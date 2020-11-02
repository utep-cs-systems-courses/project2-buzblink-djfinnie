#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

char switch_pressed = 4;

/* Switch on P2 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & S1) {	      /* did a button cause this interrupt? */
    P2IFG &= ~S1;  /* clear pending sw interrupts */
    switch_pressed = (switch_pressed +1) %3;  // Got idea from another student
    switch_interrupt_handler();	/* single handler for all switches */
  }
  else if (P2IFG & S2) {
    P2IFG &= ~S2;
    switch_pressed = 2;
  }
  else if (P2IFG & S3) {
    P2IFG &= ~S3;
    switch_pressed = 3;
  }
  else if (P2IFG & S4) {
    P2IFG &= ~S4;
    switch_pressed = 4;
    green_on = 0;
    red_on = 0;
    led_changed = 1;
    led_update();
  }
}
