/*
  Morse.cpp - Library for Temperature using LM35.
  Created by Shuvasis Datta on 26-05-2016.
*/

#include "Arduino.h"
#include "Temp.h"

Temp::Temp(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Temp::showTemp()
{
  Serial.print("Temperature : ");
  float temperature = (float)(5 * analogRead( _pin ) * 100) / 1024;  
  Serial.print( temperature );
  Serial.println(" C");
  delay(10);
}

float Temp::getTemp()
{
  float temperature = (float)(5 * analogRead( _pin ) * 100) / 1024;  
  return temperature;
}
