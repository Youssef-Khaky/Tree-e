#ifndef MotorController_h
#define MotorController_h
#include "Arduino.h"
class MotorController
{
    int motorPinA;
    int motorPinB; 
    int encoderPinA;
    int encoderPinB;
    int encoderLBPinALast;
    
public:
    MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB);
    void rotateMotorForward(void);
    void rotateMotorBackwards(void);
    void stopMotorRotation(void);
};

#endif
