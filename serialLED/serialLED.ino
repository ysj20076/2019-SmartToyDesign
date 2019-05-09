int incomingByte = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte == '1'){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("On");
    }
    else if(incomingByte == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print("Off");
    }
  }
}
