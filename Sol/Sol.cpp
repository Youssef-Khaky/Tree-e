
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

void Sol::openFor(float timeOpen)
{
  digitalWrite(_pin, HIGH);
  delay(timeOpen);
  digitalWrite(_pin, LOW);
}


// void Sol::gatec()
// {
//   digitalWrite(_pin, LOW);
//   delay(1000);
// }
