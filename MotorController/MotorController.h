#ifndef MotorController_h
#define MotorController_h
#include <PID_v1.h>
#include "Arduino.h"
class MotorController
{
public:
    volatile unsigned long int encoderValue = 0;
    int motorPinA;
    int motorPinB;
    int encoderPinA;
    int encoderPinB;
    int speedPWMPin;
    //         int LUT[50] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66, 71, 73, 78, 84, 88, 93, 97, 105, 109,
    // 120, 128, 134, 147, 160, 171, 194, 216, 240, 249,
    // 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    // 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
    int ENCODEROUTPUT = 1980;
    long previousSpeedMillis;
    long speedMillis;
    // unsigned long int encoderValue;
    double Input;
    double Output;
    double Setpoint;
    int lastRPM;

public:
    MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB, int speedPWMPin);
    void setSpeed(int RPM);
    void rotateMotorForward(int);
    void rotateMotorBackwards(int);
    void stopMotorRotation(void);
    int RPM2PWD(int RPM);
    int calculateRPM(void);
    static void updateEncoder(void);
};

#endif
