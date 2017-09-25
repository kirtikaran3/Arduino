
#include <avr/wdt.h>
int loop_count = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting up...");
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  delay (500);
  watchdogSetup();
}

void watchdogSetup(void)
{
  cli();// disable all interrupts
  wdt_reset(); // reset the WDT timer /*
  /*WDTCSR configuration:
  WDIE = 1: Interrupt Enable
  WDE = 1   :Reset Enable
  WDP3 = 0  :Set the four prescaler bits for a 2 sec timeout
  WDP2 = 1
  WDP1 = 1 
  WDP0 = 1
  */
  // Enter Watchdog Configuration mode:
  //(1<<5) generated a byte with all zeros and one 1 at the 5th (counting from zero) bit from the right.
  //hence, for example, (1<<WDCE) generates "00010000", since WDCE=4 (see datasheet 10.9.2)
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  // Set Watchdog settings:
  WDTCSR = (1<<WDIE) | (1<<WDE) | (0<<WDP3) | (0<<WDP2) | (0<<WDP1) | (0<<WDP0);
  sei();//enable interrupts
}

void loop()
{
  for (int i = 0; i <= loop_count;i++)
  {
  digitalWrite(13,HIGH); delay(100); digitalWrite(13,LOW); delay(100);//blink the built in LED as the loop counts
  }
  loop_count++;
  
  wdt_reset();//this resets the watch dog to zero. If it happens before the 2 sec timeout of the watchdog the system reset is prevented.
  
  //now print on the serial monitor the lapsed time:
  Serial.print(loop_count);
  Serial.print(". Watchdog fed in approx. "); Serial.print(loop_count*200); Serial.println(" milliseconds.");
}
  
ISR(WDT_vect) // Watchdog timer interrupt.
{ 
  Serial.println("WDT loop");
  // Include your code here - be careful not to use functions they may cause the interrupt to hang and prevent a reset.
}
