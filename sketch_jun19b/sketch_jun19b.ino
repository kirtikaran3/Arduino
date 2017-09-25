#include<LiquidCrystal.h> 

LiquidCrystal lcd(13,12,7,6,5,4); //rs,e,d4,d5,d6,d7

byte smiley[8]={
  
      0b00000, 
      0b00000, 
      0b11000, 
      0b11100, 
      0b11110, 
      0b10100, 
      0b00000, 
      0b00000 
  };
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); 
lcd.createChar(1,smiley);
}
void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(5,0);
lcd.write(1);
}
