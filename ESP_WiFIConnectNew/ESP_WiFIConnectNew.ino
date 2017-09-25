#include<ESP8266WiFi.h> 

const char* ssid = "kirti1901"; 
const char* password = "karankirti123!@#"; 

 void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  delay(10); 

    Serial.println(); 
    Serial.println();  
    Serial.print("Connecting to :"); 
    Serial.println(ssid); 

WiFi.begin(ssid,password); 



void loop() {
  // put your main code here, to run repeatedly:
 
while(WiFi.status()!=WL_CONNECTED){
  delay(500); 
  Serial.print(".");
  } 
  Serial.println(""); 
  Serial.println("WiFi Connected");
   Serial.print("You are connected to : ");
  Serial.println(ssid); 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}
  
 
}
