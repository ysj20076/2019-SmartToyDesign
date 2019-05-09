void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //내장되어 있는 LED 끄고 밝히기
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000);                       
}
