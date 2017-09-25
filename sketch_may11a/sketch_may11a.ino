#include<ESP8266WiFi.h>


void setup(){
  
  Serial.begin(115200); 
  WiFi.mode(WIFI_STA); 
  
  } 

void loop(){
  
  int n = WiFi.scanNetworks(); 

  Serial.println("Scan complete"); 

  if(n==0){
    
    Serial.println("No Network found");
    } 
   else{
    
    for(int i=0;i<n;i++){
      
      Serial.print("Network Found : "); 
      Serial.print(WiFi.SSID(i)  ); 
      Serial.print("  ");
      Serial.println(WiFi.RSSI(i)); 
      }
    
    }
  
}
