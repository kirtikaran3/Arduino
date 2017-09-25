
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"


#define DHTPIN 2    // what digital pin we're connected

// Uncomment whatever DHT sensor type you're using!
#define DHTTYPE DHT11  // DHT 11
//#define DHTTYPE DHT21  // DHT 21
//#define DHTTYPE DHT22  // DHT 22

DHT dht(DHTPIN,DHTTYPE);

const char* ssid = "DKOP Labs";
const char* password = "0987654321";
const char* mqtt_server = "mqtt.thethings.io";


#define TOKEN "ihQWXNxG-gmxVsTwWkAW8-26J0LvEQAsf_zt_Soad6s"

void setup_wifi();
void callback(char* , byte* , unsigned int );

String topic = "v2/things/" + String(TOKEN);

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
int cont = 0;

const int Onboard_LED = 2;

String msg ="{\"values\":[";

void addValue(String key, float value) {
    if (cont == 0)
    {
      msg += "{\"key\":\""+key+"\",\"value\":\""+value+"\"}";
      Serial.println(key);
      Serial.println(value);
      digitalWrite(Onboard_LED, HIGH);
    }
    else  //code below doesnt work correctly for concatenation, not used
    {
      msg += ",{\"key\":\""+key+"\",\"value\":\""+value+"\"}";   
      Serial.println(key);
      Serial.println(value);
    }
    cont++;
}

void send() {
    msg += "]}";
    client.publish((char*)topic.c_str(),(char*)msg.c_str());
    msg = "{\"values\":[";
    cont = 0;  //reset cont to zero to restart next set of data values 
}

void setup() {             
  pinMode(2, OUTPUT);    // Initialize as an output on pin 2 esp8266 12-e
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length)
{
  digitalWrite(Onboard_LED, LOW);
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe((char*)topic.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop()
{

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F\n");

  //Currently there are some server side issues with multiple strings being    //based per cycle
  //start py passing one key and value then ass more in if successful by       //uncommenting
   
    addValue("Humidity", h);
    send();
//  addValue("Temperature(Cel)",  t);
//  send();
//  addValue("Temperature(Fehr)",  f);
//  send();
//  addValue("Heat Index(Cel)",  hic); 
//  send();
//  addValue("Heat Index(Fehr)",  hif);
//  send();
  }
  delay(5000); 
}
