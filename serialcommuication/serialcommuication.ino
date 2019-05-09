int cnt;
void setup() {
  Serial.begin(9600);
  cnt = 0;
}

void loop() {
  Serial.println('a' + c);
  delay(800);
  cnt += 1;
}
