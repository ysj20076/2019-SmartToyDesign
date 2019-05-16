int in1 = 9; 
int in2 = 10; 
int enA = 3; 
int motorSpeedA = 0; 

void setup() { 
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);   
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT);     
  pinMode(in2, OUTPUT); 
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  motorSpeedA = 100;
} 
   
void loop() { 
  if (motorSpeedA < 0) { 
    motorSpeedA = 0; 
  }
  
  if (motorSpeedA > 255) { 
    motorSpeedA = 255; 
  } 
  analogWrite(enA, motorSpeedA); 
} 
 
void serialEvent() { 
  while (Serial.available()) { 
    char inChar = (char)Serial.read(); //사용자로부터 값을 입력받음
   
    if(inChar == '0') { //정지 
      digitalWrite(in1, LOW); 
      digitalWrite(in2, LOW);  
    } 
    
    else if(inChar == 'f') { //직진
      digitalWrite(in1, HIGH); 
      digitalWrite(in2, LOW); 
    } 
    
    else if(inChar == 'b') { //후진 
      digitalWrite(in1, LOW); 
      digitalWrite(in2, HIGH);   
    }
    
    else if(inChar == 'u') { //속도 증가 
      motorSpeedA += 10;
      Serial.println(motorSpeedA);
 
      if (motorSpeedA > 255) { 
        motorSpeedA = 255; 
      } 
    }  

    else if(inChar == 'd') { //속도 감소 
      motorSpeedA -= 10; 
      Serial.println(motorSpeedA);
      if (motorSpeedA < 0) { 
        motorSpeedA = 0; 
      } 
    } 
  } 
} 
