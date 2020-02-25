#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB)
{
    this-> motorPinA = motorPinA;
    this-> motorPinB = motorPinB;
    this-> encoderPinA = encoderPinA;
    this-> encoderPinB = encoderPinB;

    pinMode(this->motorPinA, OUTPUT);
    pinMode(this->motorPinB, OUTPUT);
    pinMode(this-> encoderPinA, INPUT);
    pinMode(this-> encoderPinB, INPUT);
}

// rotate motor forward
void MotorController::rotateMotorForward(void)
{
    digitalWrite(this->motorPinA, LOW);
    digitalWrite(this->motorPinB, HIGH);
}

// rotate motor backwards
void MotorController::rotateMotorBackwards(void)
{
    digitalWrite(this->motorPinA, HIGH);
    digitalWrite(this->motorPinB, LOW);
}

// stop motor from rotating
void MotorController::stopMotorRotation(void)
{
    digitalWrite(this->motorPinA, LOW);
    digitalWrite(this->motorPinB, LOW);
}