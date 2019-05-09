int IN1 = 9; 
int IN2 = 10; 
int enA = 3; 

 
int motorSpeedA = 0; 

 
void setup() { 
 Serial.begin(9600); 
pinMode(LED_BUILTIN, OUTPUT);   
 
 pinMode(enA, OUTPUT); 
 pinMode(IN1, OUTPUT);     
 pinMode(IN2, OUTPUT); 

 

 // Set initial rotation direction 
  // forward 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW); 

 
 // Initial speed 
  motorSpeedA = 100;

 } 
   
 void loop() { 
   
  
  if (motorSpeedA < 0)  
  { 
    motorSpeedA = 0; 
  }
  if (motorSpeedA > 255)  
  { 
    motorSpeedA = 255; 
  } 
     
   analogWrite(enA, motorSpeedA); // Send PWM signal to motor A 
} 

 

 

 
 void serialEvent() { 
  while (Serial.available())  
  { 
    // get the new byte: 
    char inChar = (char)Serial.read(); 
      
    if(inChar == '0') 
    { 
       digitalWrite(IN1, LOW); 
      digitalWrite(IN2, LOW); 
       
     } 
    else if(inChar == 'f') 
    { 
      digitalWrite(IN1, HIGH); 
      digitalWrite(IN2, LOW); 
        
     } 
    else if(inChar == 'b') 
   { 
      digitalWrite(IN1, LOW); 
       digitalWrite(IN2, HIGH); 
       
    }
    
    else if(inChar == 'u') 
   { 
     motorSpeedA = motorSpeedA + 10;
     Serial.println(motorSpeedA);

        if (motorSpeedA > 255)  
         { 
            motorSpeedA = 255; 
          } 
       
    }  

    else if(inChar == 'd') 
   { 
      motorSpeedA = motorSpeedA - 10;
     Serial.println(motorSpeedA);

         if (motorSpeedA < 0)  
         { 
            motorSpeedA = 0; 
          }
       
    } 
  } 
 } 

