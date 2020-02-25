
/*
 Sol.cpp is  source code for Sol library to control the gate of a solenoid 
 
 */
#include "Arduino.h"
#include "Sol.h"

Sol::Sol(int pin)
{
  pinMode(pin, OUTPUT);
  this->_pin = pin;
  
}

void Sol::gateo()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
}


void Sol::gatec()
{
  digitalWrite(_pin, LOW);
  delay(1000);
}
