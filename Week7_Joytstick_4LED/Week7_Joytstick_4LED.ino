#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
#define sw 9
#define x A0
#define y A1
int x_range_low = 0;
int x_range_high = 1023;
int y_range_low = 0;
int y_range_high = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(sw, INPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x_val = analogRead(x);
  int y_val = analogRead(y);
  int x_val_map = map(x_val,x_range_low,x_range_high,0,255);
  int y_val_map = map(y_val,y_range_low,y_range_high,0,255);

  if (x_val < x_range_high/2){
    analogWrite(LED1, x_val_map);
  }
  else if ((x_range_high/2 < x_val) & (x_val < x_range_high)){
    analogWrite(LED2, x_val_map);
  }
  else if (y_val < y_range_high/2){
    analogWrite(LED3, y_val_map);
  }
  else if ((y_range_high/2 < y_val) & (y_val < y_range_high)){
    analogWrite(LED4, y_val_map);
  }
  while (digitalRead(sw) == HIGH){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
}
