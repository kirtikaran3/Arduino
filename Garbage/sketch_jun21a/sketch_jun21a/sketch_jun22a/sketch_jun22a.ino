#include<LiquidCrystal.h> 

LiquidCrystal lcd(12,11,7,6,5,4);    //rs,e,d4,d5,d6,d7

byte smiley[8]={
  
            0b00000, 
            0b00000, 
            0b01010, 
            0b00000, 
            0b10001, 
            0b01110, 
            0b00000, 
            0b00000 
  }; 

  byte sad[8]={
  
            0b00000, 
            0b00000, 
            0b01010, 
            0b00000, 
            0b01110, 
            0b10001, 
            0b00000, 
            0b00000 
  };
  byte car[8]={
  
            0b00000, 
            0b00000, 
            0b11100, 
            0b11100, 
            0b11111, 
            0b11111, 
            0b01010, 
            0b00000 
  };


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); 
  lcd.createChar(1,smiley); 
  lcd.createChar(2,sad); 
  lcd.createChar(3,car);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0,1); 
  lcd.write(1); 
  lcd.setCursor(1,1); 
  lcd.write(2); 
  lcd.setCursor(2,1); 
  lcd.write(3); 

  
}
