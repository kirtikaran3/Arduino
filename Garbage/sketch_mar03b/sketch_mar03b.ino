#include<LiquidCrystal.h> 

LiquidCrystal lcd(12,11,10,9,8,7)       //lcd(RS,E,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); 
lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:
 
lcd.print("Embedded Class this is test of Liquid Crystal"); 
lcd.autoscroll(); 
 

}
