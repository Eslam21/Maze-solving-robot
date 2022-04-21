#include "AFMotor.h"
#define IRSensorR A0
#define IRSensorF A3
AF_DCMotor motorR (2);
AF_DCMotor motorL (1);
int IRSensorStatus_R,IRSensorStatus_Old_R=0;
int IRSensorStatus_F,IRSensorStatus_Old_F=0;
int cmd;

void setup(){
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode (IRSensorR, INPUT);
  pinMode (IRSensorF, INPUT);  
}

void loop(){
  int IRSensorStatus_R = digitalRead (IRSensorR);
  int IRSensorStatus_F = digitalRead (IRSensorF);
   
 if(IRSensorStatus_F==0)
  { 
    Serial.println("F Wall Detected");
    IRSensorStatus_Old_F = IRSensorStatus_F;
    motorR.setSpeed(88);
    motorL.setSpeed(65);
    motorR.run(FORWARD);
    motorL.run(BACKWARD);
    delay(1000);
  }
  else
  {
  if(IRSensorStatus_R==0&& IRSensorStatus_R!=IRSensorStatus_Old_R)
   {
    Serial.println("R Wall Detected");
    IRSensorStatus_Old_R = IRSensorStatus_R;  
    motorR.setSpeed(80);
    motorL.setSpeed(85);
    motorR.run(FORWARD);
    motorL.run(FORWARD);
 }
  
  else if (IRSensorStatus_R==1)
  {
  Serial.println("R empty space Detected");
  IRSensorStatus_Old_R = IRSensorStatus_R;
  motorR.setSpeed(85);
  motorL.setSpeed(70);
  motorR.run(BACKWARD);
  motorL.run(FORWARD);
 }
 else
 {}
 }
}
