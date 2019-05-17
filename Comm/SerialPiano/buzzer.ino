int incomingByte = 0; 
int piezo = 9;
int numTones = 8;
int tones[] =  {261, 294, 330, 349, 392, 440, 494, 523};

void setup() {
 Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) { 
    incomingByte = Serial.read(); 
  
    switch(incomingByte) {
      case '1':
        tone(piezo, tones[0]);
        delay(500);
        break;
      case '2':
        tone(piezo, tones[1]);
        delay(500);
        break;
      case '3':
        tone(piezo, tones[2]);
        delay(500);
        break;
      case '4':
        tone(piezo, tones[3]);
        delay(500);
        break;
      case '5':
        tone(piezo, tones[4]);
        delay(500);
        break;
      case '6':
        tone(piezo, tones[5]);
        delay(500);
        break;
      case '7':
        tone(piezo, tones[6]);
        delay(500);
        break;
      case '8':
        tone(piezo, tones[7]);
        delay(500);
        break;
    }
  }
}
