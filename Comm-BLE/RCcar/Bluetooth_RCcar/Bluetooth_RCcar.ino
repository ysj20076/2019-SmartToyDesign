#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4, 5);

int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;

int RSpeed = 255;
int LSpeed = 255;
int a = 180;

char data;

void setup() {
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    data = BTSerial.read();

    if (data == 'f') { //직진
      analogWrite(in1, 0);
      analogWrite(in2, RSpeed);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed); 
    }
    if (data == 'r') { //우회전
      analogWrite(in1, 0);
      analogWrite(in2, a);
      analogWrite(in3, 0);
      analogWrite(in4, LSpeed);
    }
    if (data == 'l') { //좌회전
      analogWrite(in1, 0);
      analogWrite(in2, LSpeed);
      analogWrite(in3, 0);
      analogWrite(in4, a);
    }
    if (data == 'b') { //후진
      analogWrite(in1, LSpeed);
      analogWrite(in2, 0);
      analogWrite(in3, RSpeed);
      analogWrite(in4, 0);
    }
    if (data == 's') { //정지
      analogWrite(in1, 0);
      analogWrite(in2, 0);
      analogWrite(in3, 0);
      analogWrite(in4, 0);
    }
  }
}
