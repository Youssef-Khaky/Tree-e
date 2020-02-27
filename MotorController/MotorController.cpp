#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB, int PWM_speed)
{
    this-> motorPinA = motorPinA;
    this-> motorPinB = motorPinB;
    this-> encoderPinA = encoderPinA;
    this-> encoderPinB = encoderPinB;
    this->PWMSpeedPid = PWMSpeedPid;
    

    pinMode(this->motorPinA, OUTPUT);
    pinMode(this->motorPinB, OUTPUT);
    pinMode(this-> encoderPinA, INPUT);
    pinMode(this-> encoderPinB, INPUT);
    pinMode(this->PWMSpeedPid, OUTPUT);
}

//
int MotorController::RPM2PWD(int RPM){
  if (RPM < 30 || RPM > 0){
    return LUT[RPM];
  } else if (RPM > 30){
    return 255;
  } else if (RPM < 0){
    return 0;
  }
}

// rotate motor forward
void MotorController::rotateMotorForward(int RPM = 30)
{
    digitalWrite(this->motorPinA, LOW);
    digitalWrite(this->motorPinB, HIGH);
    digitalWrite(this->PWMSpeedPid, this->RPM2PWD(RPM));
}

// rotate motor backwards
void MotorController::rotateMotorBackwards(int PWM_speed = 255)
{
    digitalWrite(this->motorPinA, HIGH);
    digitalWrite(this->motorPinB, LOW);
    digitalWrite(this->PWMSpeedPid, this->RPM2PWD(RPM));
}

// stop motor from rotating
void MotorController::stopMotorRotation(void)
{
    digitalWrite(this->motorPinA, LOW);
    digitalWrite(this->motorPinB, LOW);
    digitalWrite(this->PWMSpeedPid, 0);
}
