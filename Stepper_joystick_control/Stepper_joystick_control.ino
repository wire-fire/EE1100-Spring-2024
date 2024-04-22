//1-12-23 Jack McTasney
//Stepper motor controller demo (ULN2003 controller)
// IN1: 7
// IN2: 6
// IN3: 5
// IN4: 4

//Definitions (making our lives easier)
#define in1 7
#define in2 6
#define in3 5
#define in4 4  //Nice
#define x A0
#define y A1
//Global Variable(s)
int delayTime = 5;

void A() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void B() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void C() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void D() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void off() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void Forward() {
  A();
  delay(delayTime);
  B();
  delay(delayTime);
  C();
  delay(delayTime);
  D();
  delay(delayTime);
}
void Reverse() {
  D();
  delay(delayTime);
  C();
  delay(delayTime);
  B();
  delay(delayTime);
  A();
  delay(delayTime);
}
void setup() {
  // Pin initializations
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(x,INPUT); //0 --> 1023
  pinMode(y,INPUT); //0 --> 1023
}

void loop() {
  // put your main code here, to run repeatedly:
  int xin;
  unsigned long hold = millis() + 2000;  //set hold to current runtime + 2 seconds
  while (millis() < hold) {
    Forward();  // Clockwise rotation
    xin = analogRead(x);
    delayTime = map(xin, 0, 1023, 0, 5); //map(pin, fromLow, fromHigh, toLow, toHigh)
  }
  hold = millis() + 2000;  //reset hold value to current runtime + 2 seconds
  while (millis() < hold) {
    Reverse();  // Counter-clockwise rotation
  }
  delay(1000);
}
