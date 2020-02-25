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
        int RFMotorPinB)


    private: MotorController RFMotor;
    private: MotorController LFMotor;
    private: MotorController RBMotor;
    private: MotorController LBMotor;
}