#include<LiquidCrystal.h> 

LiquidCrystal lcd (13,12,11,10,9,8);    ///rs,e,d4,d5,d6,d7
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2); 

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(10,1);
lcd.print("Hello Class of Embedded..."); 
delay(1000); 
lcd.autoscroll();
}
