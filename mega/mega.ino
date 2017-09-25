#include <Event.h>
#include <Timer.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

Timer Time;
double dc,t,a,d;
long d_milli,d_micro,a_milli,a_micro;
 
String num1,num2;
double duty_cycle,k;
int stage=0;
boolean final = false;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'.','0','E','D'}
};
byte rowPins[ROWS] = {A15, A14, A13, A12}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A11, A10, A9, A8}; //connect to the column pinouts of the keypad
int i = 0;
int sample;
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
boolean in_setup = true;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  char key = customKeypad.getKey();
  lcd.setCursor(0, 1); 
  lcd.print("freq= ");
  lcd.blink();
  while( true)
  {
        char key = customKeypad.getKey();
    
            
        if(key == 'E')
        {
          if(stage == 0)
          {
            k = num1.toInt();
            Serial.println(num1);
            
            lcd.clear();
            lcd.print("f=");
            lcd.print(num1);
            lcd.print("Hz,");
            lcd.setCursor(0,1);
            lcd.print("d.cyc=");
            num1="";
          }
          if(stage == 1)
          {
            duty_cycle = num1.toInt();
            Serial.println(num1);
            lcd.clear();
            lcd.print("f=");
            lcd.print(k);
            lcd.print("Hz,d.c=");
            lcd.print(duty_cycle);
            lcd.print("%");
            lcd.noBlink();
           
          Serial.println("in stage 2");
          dc=duty_cycle*0.01;
          t=1/k;
          Serial.print("t=");
          Serial.println(t);
          
          d=t*dc; //d=total time*duty cycle(on time)
          a=t-d;  //a=off time
           Serial.print("d=");
          Serial.println(d);
           Serial.print("a=");
          Serial.println(a);
          
          d_milli = d*1000;
          
           Serial.print("d_milli=");
          Serial.println(d_milli);
          
          d_micro = (d*1000000-d_milli*1000);
           Serial.print("d_micro=");
          Serial.println(d_micro);
          a_milli = a*1000;
          Serial.print("a_milli=");
          Serial.println(a_milli);
          a_micro = (a*1000000-a_milli*1000);
          Serial.print("a_micro=");
          Serial.println(a_micro);
            if (d_micro == 0)
            {
              d_micro = 1;
            }
            if (a_micro == 0)
            {
              a_micro = 1;
            }
          Serial.println(a_milli);
          Serial.println(a_micro);
          Serial.println(d);
          break;
          
        }
          
          stage++;
          Serial.print(duty_cycle);
          Serial.print(" ");
          Serial.print(k);                
          
        }
        
        if(key != NO_KEY &&(key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'))
        {
          Serial.println("in_number");
          num1 = num1 + key;
          //int numLength = num1.length();
          //to adjust one whitespace for operator
          lcd.setCursor(6,1);
          lcd.print(num1);
          lcd.blink();
        }
        if(key == '.')
        {
          num1 = "";
          num2 = "";
          k = 1;
          duty_cycle = 50;
          lcd.clear();
          stage=0;
          continue;
        }
       Serial.print("Please enter the time period"); 
       
        key = customKeypad.getKey(); 

        unsigned int val=(key-48)*1000; //since our system works on ASCII and arduino on Hex so this is conversion for ASCII to Hex  
        //since in ascii 0=48 and 1=49 so to get 1 substract 0 from it;
        Serial.print("Time before exiting...");
        Serial.println(val);
         
        Time.after(val*1000,Exit);
   
 
}


}
// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(13, HIGH);  
  digitalWrite(12, LOW);  

  delay(d_milli);
  delayMicroseconds(d_micro);
  

//
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);  
  delay(a_milli);
  delayMicroseconds(a_micro);
  
  
} 
void Exit(){
  
  setup();
  }





