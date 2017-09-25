#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
SMSGSM sms;

int numdata;
boolean started=false;
char smsbuffer[160];
char n[20];

char sms_position;
char phone_number[20];
char sms_text[100];
int i;

void setup()
{
    Serial.begin(9600);
    
    if (gsm.begin(9600)) 
    {
        Serial.println("\nstatus=READY");
        started=true;
    } 
    else 
        Serial.println("\nstatus=IDLE");

    if(started) 
    {
        if (sms.SendSMS("+918826287022", "Arduino SMS"))
        {
          Serial.println("\nSMS sent OK.");
        }
        else
        {
          Serial.println("\nError sending SMS.");
        }      
    }
};

void loop()
{
    if(started) 
    {
        sms_position=sms.IsSMSPresent(SMS_UNREAD);
        if (sms_position) 
        {
            Serial.print("SMS postion:");
            Serial.println(sms_position,DEC);
            sms.GetSMS(sms_position, phone_number, sms_text, 100);
            Serial.println(phone_number);
            Serial.println(sms_text);
        }      
        delay(2000);
    }
};
