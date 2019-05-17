void setup() { 
  Serial.begin(9600); 
} 
 
 
void loop() { 
  int a = analogRead(A1); 
  Serial.println(a); 
  delay(100); 
} 
