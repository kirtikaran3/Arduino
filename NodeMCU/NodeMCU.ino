#include<DHT.h>

#include<ESP8266WiFi.h> 

String apiKey="85W4LH6EI7X0SYZE"; 
const char* ssid = "kirti"; 
const char* password = "karankirti123!@#";  
const char* server="api.thingspeak.com"; 

 #define DHTPIN D2 //D7 nodeMCU  

 DHT dht(DHTPIN,DHT11);  
 WiFiClient client; 
 
 void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
delay(10); 
dht.begin();

WiFi.begin(ssid,password); 

Serial.println(); 
Serial.println();  
Serial.print("Connecting to :"); 
Serial.println(ssid); 

WiFi.begin(ssid,password); 

while(WiFi.status()!=WL_CONNECTED){
  delay(500); 
  Serial.print(".");
  } 
  Serial.println(""); 
  Serial.println("WiFi Connected");
}

void loop() {
  // put your main code here, to run repeatedly:

float h = dht.readHumidity(); 
float t = dht.readTemperature(); 

if(isnan(h)||isnan(t)){
  
  Serial.println("failed to read DHT"); 
  return;
  }  
  if(client.connect(server,80)){

String postStr=apiKey; 
postStr +="&field1="; 
postStr +=String(t); 
postStr +="&field2="; 
postStr +=String(h); 
postStr +="\r\n\r\n"; 

    client.print("POST /update HTTP/1.1\n"); 
    client.print("Host: api.thingspeak.com\n"); 
    client.print("Connection: close\n"); 
    client.print("X-THINGSPEAKAPIKEY:"+apiKey+"\n"); 
    client.print("Content-Type:application/x-www-form-urlencoded\n"); 
    client.print("Content-Length:"); 
    client.print(postStr.length());
    client.print("\n\n"); 
    client.print(postStr);

        Serial.print("Temperature: "); 
        Serial.print(t); 
        Serial.print("Degree Celcius Humidity"); 
        Serial.print(h); 
        Serial.println("% send to Thingspeak");
    } 
    client.stop(); 
    Serial.println("Waiting"); 
    delay(20000);
} 








