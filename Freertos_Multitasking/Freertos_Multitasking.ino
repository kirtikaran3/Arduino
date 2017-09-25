#include <Arduino_FreeRTOS.h>


void TaskBlink( void *pvParameters );
void TaskToggle( void *pvParameters );


void setup() {

  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *)"Blink"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskToggle
    ,  (const portCHAR *) "AnalogRead"
    ,  128 // This stack size can be checked & adjusted by reading Highwater
    ,  NULL
    ,  1  // priority
    ,  NULL );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop(){
  // Empty. Things are done in Tasks.
}

void TaskBlink(void *pvParameters){
  (void) pvParameters;

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  for (;;) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }

}

void TaskToggle(void *pvParameters){
  (void) pvParameters;
  pinMode(3,OUTPUT); 
 for(;;){
    digitalWrite(3,HIGH);  
    // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 100 / portTICK_PERIOD_MS ); // wait for one second 
   
 }
   
  
} 



