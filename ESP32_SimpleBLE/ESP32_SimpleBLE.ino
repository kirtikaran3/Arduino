#include "SimpleBLE.h"
SimpleBLE ble;

void onButton(){
    String out = "BLE32 at: ";
    out += String(millis() / 1000);
    Serial.println(out);
    ble.begin(out);
}

void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    pinMode(0, INPUT_PULLUP);
    Serial.print("ESP32 SDK: ");
    Serial.println(ESP.getSdkVersion());
    ble.begin("ESP32 SimpleBLE");
    Serial.println("Press the button to change the device name");
}

void loop() {
    static uint8_t lastPinState = 1;
    uint8_t pinState = digitalRead(0);
    if(!pinState && lastPinState){
        onButton();
    }
    lastPinState = pinState;
    while(Serial.available()) Serial.write(Serial.read());
}
