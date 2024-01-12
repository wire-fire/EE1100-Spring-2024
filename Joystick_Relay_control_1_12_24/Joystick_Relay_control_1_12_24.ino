//11-12-24 Jack McTasney
//relay motor controlled by joystick demo
//NOTES:
//The mega does not like using it's own power to drive the motor with digitalWrite(HIGH) 
//try using a diff power source


//Wiring!!!!
//VRX:   A1
//VRY:   A0
//SW:     3
//relay: 22

//Definitions (making our lives easier)
#define vrX A1
#define vrY A0
#define sw 3
#define relay 22

void joystickRelay(){
  //Controls relay switching speed with joystick Y input
  int joyX=analogRead(vrX);
  int joyY=analogRead(vrY);
  Serial.print("Joystick X: ");
  Serial.print(joyX);
  Serial.print(" | Joystick Y: ");
  Serial.println(joyY);
  long speed=map(joyY,0,1023,5,1000);
  digitalWrite(relay,HIGH);
  delay(speed);
  digitalWrite(relay,LOW);
  delay(speed);
}

void setup() {
  // put your setup code here, to run once:
  //Inits
  pinMode(vrX,INPUT);
  pinMode(vrY,INPUT);
  pinMode(sw,INPUT);
  pinMode(relay,OUTPUT);
  //Serial monitor init
  Serial.begin(9600); //begin at 9600 baud
  //Testing relay
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystickRelay();
}
