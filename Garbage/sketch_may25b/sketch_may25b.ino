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


void TaskBlink( void *pvParameters );

int count=0; 
int previous=LOW;
void setup() {
  // put your setup code here, to run once:
  xTaskCreate(
    TaskBlink
    ,  (const portCHAR *) "Count"
    ,  128 // This stack size can be checked & adjusted by reading Highwater
    ,  NULL
    ,  1  // priority
    ,  NULL );


 
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  
} 

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize digital pin 13 as an output.
  pinMode(13, INPUT);

  for (;;) // A Task shall never return or exit.
  {
    int current=digitalRead(13); 

  if(current!=previous){

          if(current==HIGH){ 
 
              count++;
              Serial.println(count);
            }   
      previous=current;
    } 
    if(count==1){
      digitalWrite(1,HIGH);
      } 
     if(count==2){
      digitalWrite(2,HIGH);
      }   
      if(count==3){
        digitalWrite(6,HIGH); 
        
         } 
        if(count==4){
          digitalWrite(7,HIGH);
          } 
              
               }
} 







