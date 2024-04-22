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
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x_val = analogRead(x);
  int y_val = analogRead(y);
  int x_val_map = map(x_val, x_range_low, x_range_high, 0, 255);
  int y_val_map = map(y_val, y_range_low, y_range_high, 0, 255);
  Serial.print("x_val: ");
  Serial.println(x_val);
  Serial.print("y_val: ");
  Serial.println(y_val);
  Serial.print("x_val_map: ");
  Serial.println(x_val_map);
  Serial.print("y_val_map: ");
  Serial.println(y_val_map);

  if (((510 < x_val) && (x_val < 530)) && ((510 < y_val) && (y_val < 530))) {  //Neutral
    x_val = analogRead(x);
    y_val = analogRead(y);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    delay(10);  //stability
  } else {

    if (x_val < x_range_high / 2) {  // 0 --> 511
      analogWrite(LED1, y_val/2);
    }
    else if (x_range_high / 2 < x_val) {  // 511 --> 1023
      analogWrite(LED2, x_val/2 - 512);
    }
    if (y_val < y_range_high / 2) {  // 0 --> 511
      analogWrite(LED3, y_val/2);
    }
    else if (y_range_high / 2 < y_val) {  // 511 --> 1023
      analogWrite(LED4, y_val/2 - 512);
    }
  }
  while (digitalRead(sw) == LOW) {
    Serial.println(digitalRead(sw));
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }
  delay(2);
}
