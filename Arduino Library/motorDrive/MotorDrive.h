/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef MotorDrive_h
#define MotorDrive_h

#include "Arduino.h"

class MotorDrive{
	public:
		MotorDrive(int pin1,int pin2, int pin3, int pin4, int rpm1, int rpm2); 
		void forward();
		void backward();
		void hardLeft();
		void hardRight();
		void softLeft();
		void softRight();
		void stop();
	private:
		int dirA, dirB, pwmA, pwmB, rpmA, rpmB;
};

#endif
