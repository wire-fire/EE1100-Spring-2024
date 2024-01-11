//1-11-24 Jack McTasney
//4x1 7 segment test code with ATMEGA2560 
//Wired:
// 42: E    43: D1
// 44: D    45: A
// 46: DP   47: F
// 48: C    49: D2
// 50: G    51: D3
// 52: D4   53: B
// Pull D# Low with A-->G (or DP) High to turn on segment!

//Define statements to make code more legible
#define A 45
#define B 53
#define C 48
#define D 44
#define E 42
#define F 47
#define G 50
#define DP 46
#define digit1 43
#define digit2 49
#define digit3 51
#define digit4 52




void setup() {
  // Alot of outputs, I am not excited
  pinMode(E,OUTPUT);
  pinMode(digit1,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(DP,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(digit2,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(digit3,OUTPUT);
  pinMode(digit4,OUTPUT);
  pinMode(B,OUTPUT);
  // Reverse-bias all diodes (display off hopefully)
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  digitalWrite(DP,LOW);
  digitalWrite(digit1,HIGH);
  digitalWrite(digit2,HIGH);
  digitalWrite(digit3,HIGH);
  digitalWrite(digit4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
