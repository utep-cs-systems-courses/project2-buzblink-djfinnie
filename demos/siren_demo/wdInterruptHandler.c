#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int count = 0;
  extern char switch_pressed = 0;

  if ((++count %25) == 0) buzzer_advance();

  if (count == 250) {
    main_state_advance();
    count = 0;
  }

  switch (switch_pressed) {
  case 0:
    button1_state_advance();

  case 1:
    button2_siren();

  case 2:
    button3_high();

  case 3:
    button4_off();
  }  
  
  if (++blink_count == 125) {
    buzzer_advance();
    state_advance();
    blink_count = 0;
  }
}
