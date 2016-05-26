/*
  MotorDrive.h - Library for Motor Drive.
  Created by Mushfiq Shovon on 27.05.2016
*/

#include "Arduino.h"
#include "MotorDrive.h"

MotorDrive::MotorDrive(int pin1, int pin2, int pin3, int pin4, int rpm1, int rpm2){
	dirA = pin1;
	pwmA = pin2;
	pwmB = pin3;
	dirB = pin4;
	rpmA = rpm1;
	rpmB = rpm2;
}

void MotorDrive::forward()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
 }
 
void MotorDrive::backward()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, LOW);
   digitalWrite(dirB, HIGH);
 }

void MotorDrive::hardright()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, HIGH);
 }

 void MotorDrive::hardleft()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, LOW);
   digitalWrite(dirB, LOW);
 }

 void MotorDrive::softRight()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,0);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
}
 void MotorDrive::softLeft()
{
   analogWrite(pwmA,0);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, LOW);
}