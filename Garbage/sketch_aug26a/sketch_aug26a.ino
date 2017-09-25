int m1p = 13;
int m1n = 12;
int m2p = 11;
int m2n = 10;
int button1 = 2;
int button2 = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1p, OUTPUT);
  pinMode(m1n, OUTPUT);
  pinMode(m2p, OUTPUT);
  pinMode(m2n, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int ret1 = digitalRead(button1);
  int ret2 = digitalRead(button2);

  if ((ret1 == HIGH) && (ret2 == HIGH)) {

    digitalWrite(m1p, HIGH);
    digitalWrite(m2p, HIGH);
    digitalWrite(m1n, LOW);
    digitalWrite(m2n, LOW);

  }
  if ((ret1 == LOW) && (ret2 == LOW)) {

    digitalWrite(m1p, LOW);
    digitalWrite(m2p, LOW);
    digitalWrite(m1n, HIGH);
    digitalWrite(m2n, HIGH);

  }
  if ((ret1 == HIGH) && (ret2 == LOW)) {

    digitalWrite(m1p, HIGH);
    digitalWrite(m2p, LOW);
    digitalWrite(m1n, LOW);
    digitalWrite(m2n, LOW);

  }
  if ((ret1 == LOW) && (ret2 == HIGH)) {

    digitalWrite(m1p, LOW);
    digitalWrite(m2p, HIGH);
    digitalWrite(m1n, LOW);
    digitalWrite(m2n, LOW);

  }


}






