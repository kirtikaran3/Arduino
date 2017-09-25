
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "DKOP Labs"
#define WLAN_PASS       "0987654321"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "kirtiIoTDemo"
#define AIO_KEY         "4c7efd91af844482bc84c7b98322c11e"

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Button = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(BUILTIN_LED,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.println(F("Adafruit MQTT demo"));

  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&Button);

}

uint32_t x=0;

void loop() {

 MQTT_connect();

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &Button) {
      Serial.print(F("Got_Button: "));
      Serial.println((char *)Button.lastread);
      uint16_t num = atoi((char *)Button.lastread);
      digitalWrite(BUILTIN_LED,num);
    }

  }
}
void MQTT_connect() {
  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {  // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
