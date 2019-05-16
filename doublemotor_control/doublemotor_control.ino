int in1 = 9;
int in2 = 6;
int in3 = 10;
int in4 = 11;
int enA = 5
int enB = 12;

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); 
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(in1, OUTPUT);    
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);    
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  //초기 스피드
  motorSpeedA = 128; // 스피드 범위 : 0~255, 중간속도로 맞춤
  motorSpeedB = 128;
}

void loop() {
  if (motorSpeedA < 0) {
    motorSpeedA = 0;
  }
  
  if (motorSpeedA > 255) {
    motorSpeedA = 255;
  }

  if (motorSpeedB < 0) {
    motorSpeedB = 0;
  }

  if (motorSpeedB > 255) {
    motorSpeedB = 255;
  }
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor A
}

void serialEvent() {
  while (Serial.available()) {

    //사용자로부터 값 입력받음
    char inChar = (char)Serial.read();

    if(inChar == '0') { //stop
      digitalWrite(IN1, LOW); 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW); 
      digitalWrite(IN4, LOW);
    }
    
    else if(inChar == 'f') { //직진
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }

    else if(inChar == 'b') { //후진
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    else if(inChar == 'w') { //속도 증가
       motorSpeedA += 5; //A모터 스피드 증가
       motorSpeedB += 5; //B모터 스피드 증가

       Serial.println(motorSpeedA); //A모터 속도 시리얼모니터 출력

       //A모터나 B모터가 255를 넘으면 둘 다 255
       if (motorSpeedA > 255 || motorSpeedB > 255) {  
          motorSpeedA = 255;
          motorSpeedB = 255;
       }
    }

    else if(inChar == 's') { //속도 감소
       motorSpeedA -= 5;
       motorSpeedB -= 5;
       
       Serial.println(motorSpeedA); //B모터 속도 시리얼모니터 출력

       //A모터나 B모터가 0 미만이 되면 둘다 0
       if (motorSpeedA < 0 || motorSpeedB < 0) { 
          motorSpeedA = 0;
          motorSpeedB = 0;
       }
    }
  }
}
