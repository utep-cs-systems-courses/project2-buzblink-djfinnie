#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHESB);	/* if switch up, sense down */
  // P2IES &= (p2val | ~SWITCHESB);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHESB;		/* enables resistors for switches */
  P2IE |= SWITCHESB;		/* enable interrupts from switches */
  P2OUT |= SWITCHESB;		/* pull-ups for switches */
  P2DIR &= ~SWITCHESB;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = !switch_state_down;
  switch_state_changed = switch_state_changed;
  led_update();
}
