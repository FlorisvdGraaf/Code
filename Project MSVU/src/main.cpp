#include <Arduino.h>

// put function declarations here:
const int xpin = A0;
const int Sharp = A1;
int DriveDir_Forward = 47;
const int Deadband = 15;
int xPosition;
int Amp;
int xSpeed;
int test;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  pinMode(DriveDir_Forward, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  xPosition = analogRead(xpin);
if (xPosition >=(500 - Deadband) && xPosition <=(500 + Deadband)) { //tussen 485+515
  Serial.println("Direction = Stopped\n");
  Serial.println(xPosition);
  analogWrite(2,0);
  delay(1000);
  }
else if (xPosition >500 + Deadband) {  //Groter dan 515
  Serial.println("Direction = Backwards\n");
  Serial.println(xPosition); 
  int mappedValue = map(xPosition, 500, 0, 255, 0);
 
  Serial.println("Mapped Value:");
  Serial.println(mappedValue);
  analogWrite(2,mappedValue);
  delay(100);
  }
else if (xPosition < 500 - Deadband) {
  Serial.println("Direction = Backwards\n");
  Serial.println(xPosition); 
  int mappedValue = map(xPosition, 500, 0, 0, 255);
 
  Serial.println("Mapped Value:");
  Serial.println(mappedValue);
  analogWrite(2,mappedValue);
  //delay(100);
  }
  
  }



