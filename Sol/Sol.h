
/* 
Sol.h is a library file can be used to control a solenoid gate
two functions are used to open and close the gate with dealy of 1 s between each

Created on Feb 21, 2020
 
 */
#ifndef Sol_h
#define Sol_h

#include "Arduino.h"

class Sol
{ 
  public:
     Sol(int pin);
     void openFor();
   //   void gatec();
  private:
      int _pin;
  
};

#endif
