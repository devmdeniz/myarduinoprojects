
#include "NewPing.h"
#include<Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9

#define MAX_DISTANCE 400  

Servo servoM;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;

int pos = 0;

void setup() 
{
    servoM.attach(10);
  Serial.begin(9600);
}

void loop() 
{
  distance = sonar.ping_cm();


  if(distance < 5) {
    servoM.write(180);
    delay(1000);
    servoM.write(0);
  }





  
  Serial.print("Mesafe = ");
  
  if (distance >= 400 || distance <= 2) 
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
