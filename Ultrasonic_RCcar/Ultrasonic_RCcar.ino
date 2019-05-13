int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int trig = 2;
int echo = 3;

int LSpeed = 255;
int RSpeed = 255;

int a = 185;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration =
    pulseIn(echo, HIGH);
  float distance = duration / 29.0 / 2.0;

  Serial.println(distance);

  if (distance < 8) {
    //정지
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
    delay(700);

    //후진
    analogWrite(in1, LSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, RSpeed);
      analogWrite(in4, 0);
      delay(500);

    //좌회전
    analogWrite(in1, 0);
      analogWrite(in2, LSpeed);
      analogWrite(in3, 0);
      analogWrite(in4, a);
    delay(500);
  }

  else { 
    // 직진
    analogWrite(in1, 0);
      analogWrite(in2, RSpeed);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
  }
}
