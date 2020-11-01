#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

extern char switch_pressed;
static int count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  switch (switch_pressed) {
  case 0:
    state_advance();
    break;

  case 1:
    if (count == 250) {
      main_state_advance();
      count = 0;
    }
    if ((++count %25) == 0) buzzer_advance();
    main_state_advance();
    break;

  case 2:
    button3_siren();
    break;

  case 3:
    button4_off();
    break;
  }  

}
