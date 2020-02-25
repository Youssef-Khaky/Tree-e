#ifndef MotorController_h
#define MotorController_h
#include "Arduino.h"
class MotorController
{
    int motorPinA;
    int motorPinB; 
    int encoderPinA;
    int encoderPinB;

public:
    MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB);
    void rotateMotorForward(void);
    void rotateMotorBackwards(void);
    void stopMotorRotation(void);
};

#endif
