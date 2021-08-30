#include <Servo.h>

Servo myservo;
int pos = 0;

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for sync
  }
  Serial.println("READY");
}

void loop() {
  if (Serial.available() > 0) {
  
    String input = Serial.readString();

    input.trim();
    
    if (input == "TRIG") {
      Serial.println("Ejecting one cat treat.");  
      digitalWrite(LED_BUILTIN, HIGH); 
      myservo.attach(9);
      for (pos = 60; pos <= 135; pos += 5) { 
        myservo.write(pos);           
        delay(250);
      }
      myservo.write(168);             
      delay(2000);
      for (pos = 10; pos <= 150; pos += 5) { 
        myservo.write(170-pos);       
        delay(250);
      }
      delay(2000);
      for (pos = 20; pos <= 80; pos += 5) { 
        myservo.write(pos);           
        delay(250);
      }    
      myservo.write(60);              
      delay(250);
      myservo.write(80);              
      delay(250);
      myservo.write(60);              
      delay(250);
      myservo.write(80);              
      delay(250);
      myservo.write(60);              
      myservo.detach();
      digitalWrite(LED_BUILTIN, LOW);  
    }    
  }
}
