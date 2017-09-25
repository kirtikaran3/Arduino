#define FACTORYRESETBAUD 57600
#define DEFAULTBAUD 115200

char str[3];
char passkey[5] = "0000";

boolean success = false;
void RunBlueSmirfSetup(boolean factoryReset);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
RunBlueSmirfSetup(true);
while(Serial.available()>0){
  
  int ret=Serial.read();
  Serial.print("Value is:"); 
  Serial.println(ret);
  }
} 
void RunBlueSmirfSetup(boolean factoryReset) {

  //Initialize serial ports
  if (factoryReset) {
    Serial.begin(FACTORYRESETBAUD);   
  } else {
    Serial.begin(DEFAULTBAUD);   
  }
  }
