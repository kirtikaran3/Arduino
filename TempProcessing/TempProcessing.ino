#include<LiquidCrystal.h>
#define sensor A0
float analog_value;
LiquidCrystal lcd(2,3,4,5,6,7);

byte degree[8] =
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

void setup()
{
   lcd.createChar(1, degree);
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(sensor, INPUT);
 
  lcd.setCursor(0,0);
  lcd.print("Temperature Plot");
  lcd.setCursor(0,1);
  lcd.print("Using Proccesing");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" By KIRTI KARAN ");
  lcd.setCursor(0,1);
  lcd.print("DKOPLABS");
  delay(2000);
  lcd.clear();
}

void loop()
{
  float reading=analogRead(sensor);
  analog_value=reading*(5.0/1023.0)*100;
 
  lcd.setCursor(0,0);
  lcd.print("  Temperature  ");
  lcd.setCursor(4,1);
  lcd.print(analog_value);
  lcd.write(1);
  lcd.print("C");
  Serial.println(analog_value);
  delay(700);
}

