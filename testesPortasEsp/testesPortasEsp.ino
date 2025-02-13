#define pin1 14
#define pin2 21
#define pin3 22
#define pin4 26


void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

}

void loop() {
  digitalWrite(pin1, HIGH);
  delay(200);
  digitalWrite(pin1, LOW);
  delay(200);
//===========================================================
digitalWrite(pin2, HIGH);
delay(200);
digitalWrite(pin2, LOW);
delay(200);
//===========================================================
digitalWrite(pin3, HIGH);
delay(200);
digitalWrite(pin3, LOW);
delay(200);
//===========================================================
digitalWrite(pin4, HIGH);
delay(200);
digitalWrite(pin4, LOW);
delay(200);
//===========================================================


}
