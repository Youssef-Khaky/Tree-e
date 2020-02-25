#ifndef RobotMotionLibrary_h
#define RobotMotionLibrary_h
#include "MotorController.h"

class RobotMotionLibrary
{

public:
    RobotMotionLibrary(
        int encoderLBMotorPinA,
        int encoderLBMotorPinB,
        int encoderLFMotorPinA,
        int encoderLFMotorPinB,
        int encoderRBMotorPinA,
        int encoderRBMotorPinB,
        int encoderRFMotorPinA,
        int encoderRFMotorPinB,
        int LBMotorPinA,
        int LBMotorPinB,
        int LFMotorPinA,
        int LFMotorPinB,
        int RBMotorPinA,
        int RBMotorPinB,
        int RFMotorPinA,
        int RFMotorPinB);

    MotorController RFMotor;
    MotorController LFMotor;
    MotorController RBMotor;
    MotorController LBMotor;

    void MoveForward(void);
    void reverse(void);
    void Stop(void);
    void Left(void);
    void Right(void);
};
#endif