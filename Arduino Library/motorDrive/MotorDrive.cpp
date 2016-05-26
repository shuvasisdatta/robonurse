/*
  MotorDrive.h - Library for Motor Drive.
  Created by Mushfiq Shovon on 27.05.2016
*/

#include "Arduino.h"
#include "MotorDrive.h"

MotorDrive::MotorDrive(int pin1, int pin2, int pin3, int pin4, int rpm1, int rpm2){
	// PinMode Decleration.
	pinMode(pin1, OUTPUT);
	pinMode(pin4, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pin3, OUTPUT);
	
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

void MotorDrive::hardRight()
{
   analogWrite(pwmA,rpmA);
   analogWrite(pwmB,rpmB);
   digitalWrite(dirA, HIGH);
   digitalWrite(dirB, HIGH);
 }

 void MotorDrive::hardLeft()
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

void MotorDrive::stop()
{
   analogWrite(pwmA,0);
   analogWrite(pwmB,0);
}