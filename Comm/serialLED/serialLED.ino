int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte == '1'){ //시리얼 모니터에 1 입력
      digitalWrite(LED_BUILTIN, HIGH); //불 켜짐
      Serial.print("On"); //모니터에 On 출력
    }
    else if(incomingByte == '0') { //시리얼 모니터에 0입력
      digitalWrite(LED_BUILTIN, LOW); //불 꺼짐
      Serial.print("Off"); //모니터에 Off 출력
    }
  }
}
