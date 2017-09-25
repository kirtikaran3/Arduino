#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
}; 
byte arrow[9]={
  0b00000,
  0b01000,
  0b00100,
  0b00010,
  0b11111,
  0b00010,
  0b00100,
  0b01000, 
  0b00000 
  }; 
byte car[8]={
  0b11100,
  0b11100,  
  0b11011, 
  0b11111, 
  0b11111, 
  0b01010, 
  0b00000
 };

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(1, heart);
  // create a new character
  lcd.createChar(2, smiley);
  // create a new character
  lcd.createChar(3, frownie);
  // create a new character
  lcd.createChar(4, armsDown);
  // create a new character
  lcd.createChar(5, armsUp); 
  lcd.createChar(6,arrow); 
  lcd.createChar(7,car);
} 
void loop(){
  lcd.setCursor(4,1); 
  lcd.write(1); 
  delay(1000); 
  lcd.clear(); 
  lcd.write(2); 
  delay(1000); 
  lcd.clear(); 
  lcd.write(3); 
  delay(1000); 
  lcd.clear(); 
  lcd.write(4); 
  delay(1000); 
  lcd.clear(); 
  lcd.write(5); 
  delay(1000); 
  lcd.clear(); 
  lcd.write(6); 
  delay(1000); 
  lcd.clear();  
  lcd.write(7); 
  delay(1000); 
  lcd.clear();  
  
 }
