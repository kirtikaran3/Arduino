#include<LiquidCrystal.h> 
LiquidCrystal lcd(12,11,10,9,8,7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); 

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,1);
lcd.print("Kirti karan embedded class dkop"); 
lcd.autoscroll(); 
//delay(1000); 
//lcd.clear(); 
delay(1000);
}
