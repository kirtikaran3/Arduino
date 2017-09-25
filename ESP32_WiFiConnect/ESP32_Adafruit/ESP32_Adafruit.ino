
#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"


#define WLAN_SSID       "D-1901"
#define WLAN_PASS       "@$machine30#*"


#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "KitsIOT"
#define AIO_KEY         "b82d41d25797407c904310c7ebd5c661"


// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Button = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Button");

Adafruit_MQTT_Subscribe Swipe = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/swipe");

void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
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
  mqtt.subscribe(&Swipe);
}

uint32_t x=0;

void loop() {

 MQTT_connect();

Serial.println("In loop again");
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription())) {
    if (subscription == &Button) {
      Serial.println("Reading button");
      Serial.print(F("Got_Button: "));
      Serial.println((char *)Button.lastread);
      uint16_t num = atoi((char *)Button.lastread);
      digitalWrite(16,num);
    }

    if (subscription == &Swipe) {
      Serial.print(F("Got_swipe: "));
      Serial.println((char *)Swipe.lastread);
      uint16_t num = atoi((char *)Swipe.lastread);
      digitalWrite(5,num);
    }
  }

  // Now we can publish stuff!
//  Serial.print(F("\nSending photocell val "));
//  Serial.print(x);
//  Serial.print("...");
//  if (! photocell.publish(x++)) {
//    Serial.println(F("Failed"));
//  } else {
//    Serial.println(F("OK!"));
//  }

  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  /*
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
  */
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
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
