
int motor1Pin1 = 3; // pin 7 on L298N IC
int motor1Pin2 = 4; // pin 5 on L293N IC
int motor2Pin1 = 11; // pin 10 on L293N IC
int motor2Pin2 = 10; // pin 12 on L293N IC
int state;
int flag=0;        //makes sure that the serial only prints once the state
int stateStop=0;
void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    // if the state is 'A' the DC motor will go forward
    if (state == 'A') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Go Forward!");
          flag=1;
        }
    }
    
    // if the state is 'C' the motor will turn left
    else if (state == 'C') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Turn LEFT");
          flag=1;
        }
        delay(100);
        state=3;
        stateStop=1;
    }
    // if the state is 'E' the motor will Stop
    else if (state == 'E' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    // if the state is 'D' the motor will turn right
    else if (state == 'D') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("Turn RIGHT");
          flag=1;
        }
        delay(100);
        state=3;
        stateStop=1;
    }
    // if the state is 'B' the motor will Reverse
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("Reverse!");
          flag=1;
        }
    }
    //For debugging purpose
    //Serial.println(state);
}
