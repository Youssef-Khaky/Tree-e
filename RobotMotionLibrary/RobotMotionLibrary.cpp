
#include "Arduino.h"
#include "MotorController.h"
RobotMotionLibrary::RobotMotionLibrary(
    int RFMotorPinA,
    int RFMotorPinB,
    int encoderRFMotorPinA,
    int encoderRFMotorPinB,
    int LFMotorPinA,
    int LFMotorPinB,
    int encoderLFMotorPinA,
    int encoderLFMotorPinB,
    int RBMotorPinA,
    int RBMotorPinB,
    int encoderRBMotorPinA,
    int encoderRBMotorPinB,
    int LBMotorPinA,
    int LBMotorPinB,
    int encoderLBMotorPinA,
    int encoderLBMotorPinB
    )
{
    this->RFMotor = MotorController(RFMotorPinA, RFMotorPinB, encoderRFMotorPinA, encoderRFMotorPinB);
    this->LFMotor = MotorController(LFMotorPinA, LFMotorPinB, encoderLFMotorPinA, encoderLFMotorPinB);
    this->RBMotor = MotorController(RBMotorPinA, RBMotorPinB, encoderRBMotorPinA, encoderRBMotorPinB);
    this->LBMotor = MotorController(LBMotorPinA, LBMotorPinB, encoderLBMotorPinA, encoderLBMotorPinB);
}

void RobotMotionLibrary::MoveForward(void)
{
    this->RFMotor.rotateMotorForward();
    this->LFMotor.rotateMotorForward();
    this->RBMotor.rotateMotorForward();
    this->LBMotor.rotateMotorForward();
}

void RobotMotionLibrary::reverse(void)
{
    this->RFMotor.rotateMotorBackwards();
    this->LFMotor.rotateMotorBackwards();
    this->RBMotor.rotateMotorBackwards();
    this->LBMotor.rotateMotorBackwards();
}

void RobotMotionLibrary::Stop(void)
{
    this->RFMotor.stopMotorRotation();
    this->LFMotor.stopMotorRotation();
    this->RBMotor.stopMotorRotation();
    this->LBMotor.stopMotorRotation();
}

void RobotMotionLibrary::Left(void)
{
    this->RFMotor.rotateMotorForward();
    this->LFMotor.rotateMotorBackwards();
    this->RBMotor.rotateMotorForward();
    this->LBMotor.rotateMotorBackwards();
}

void RobotMotionLibrary::Right(void)
{
    this->RFMotor.rotateMotorBackwards();
    this->LFMotor.rotateMotorForward();
    this->RBMotor.rotateMotorBackwards();
    this->LBMotor.rotateMotorForward();
}
