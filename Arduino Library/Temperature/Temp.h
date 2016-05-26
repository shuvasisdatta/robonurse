/*
  Temp.h - Library for flashing Temperature Library.
  Created by Shuvasis Datta on 26-05-2016.
*/
#ifndef Temp_h
#define Temp_h

#include "Arduino.h"

class Temp
{
  public:
    Temp(int pin);
    void showTemp();
    float getTemp();
  private:
    int _pin;
};

#endif