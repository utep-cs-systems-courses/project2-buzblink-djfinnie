#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */

  switch_init(); //Initializes the switches.

  led_init();    //Initializes the LEDs.

  buzzer_init(); //Initializes the buzzer.

  enableWDTInterrupts();/* enable periodic interrupt */

  or_sr(0x18);/* CPU off, GIE on */
}
