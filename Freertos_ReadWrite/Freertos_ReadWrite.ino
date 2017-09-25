#include <Arduino_FreeRTOS.h>
#include <croutine.h>
#include <event_groups.h>
#include <FreeRTOSConfig.h>
#include <FreeRTOSVariant.h>
#include <list.h>
#include <mpu_wrappers.h>
#include <portable.h>
#include <portmacro.h>
#include <projdefs.h>
#include <queue.h>
#include <semphr.h>
#include <StackMacros.h>
#include <task.h>
#include <timers.h>

//#include <Arduino_FreeRTOS.h>


void TaskBlink(void *pvParameters); 
void TaskRead(void *pvparameters); 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
xTaskCreate(
  
  TaskBlink,
  (const portCHAR *)"Blink",  
  128,
  NULL, 
  2, 
  NULL
   );

    xTaskCreate(
        
        TaskRead, 
        (const portCHAR *)"READ", 
        128,      
        NULL, 
        1, 
        NULL
       );     
}

void loop() {
  // put your main code here, to run repeatedly:

} 

void TaskBlink(void *pvParameters){
  
  (void) pvParameters; 
  pinMode(13,OUTPUT); 

  for(;;){
    digitalWrite(13,HIGH); 
    vTaskDelay(1000/portTICK_PERIOD_MS); 
    digitalWrite(13,LOW); 
    vTaskDelay(1000/portTICK_PERIOD_MS);
    }
  
  }
void TaskRead(void *pvParameters){
  
  (void) pvParameters; 
  pinMode(A0,INPUT); 
  pinMode(5,OUTPUT);
  for(;;){
    int ret=analogRead(A0); 
    int value=map(ret,0,1023,0,255); 
    analogWrite(5,value); 
    Serial.println(value);
    }
  }





