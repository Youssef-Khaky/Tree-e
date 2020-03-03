#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB, int speedPWMPin)
{
  this->motorPinA = motorPinA;
  this->motorPinB = motorPinB;
  this->encoderPinA = encoderPinA;
  this->encoderPinB = encoderPinB;
  this->speedPWMPin = speedPWMPin;

  pinMode(this->motorPinA, OUTPUT);
  pinMode(this->motorPinB, OUTPUT);
  pinMode(this->encoderPinA, INPUT);
  pinMode(this->encoderPinB, INPUT);
  pinMode(this->speedPWMPin, OUTPUT);
  lastRPM = 0;

  previousSpeedMillis = millis();
}

//
int MotorController::RPM2PWD(int RPM)
{

  if (RPM < 30 && RPM >= 10)
  {
    double p1 = 4.0381e-07;
    double p2 = -7.1966e-05;
    double p3 = 0.0056047;
    double p4 = -0.25022;
    double p5 = 7.054;
    double p6 = -130.17;
    double p7 = 1571.6;
    double p8 = -11969;
    double p9 = 52166;
    double p10 = -99079;

    double PWM = p1 * pow(RPM, 9) + p2 * pow(RPM, 8) +
                 p3 * pow(RPM, 7) + p4 * pow(RPM, 6) +
                 p5 * pow(RPM, 5) + p6 * pow(RPM, 4) +
                 p7 * pow(RPM, 3) + p8 * pow(RPM, 2) +
                 p9 * RPM + p10;
    return (int)PWM;
  }
  else if (RPM >= 30)
  {
    return 255;
  }
  else if (RPM < 10)
  {
    return 0;
  }
}

// rotate motor forward
void MotorController::rotateMotorForward(int RPM = 30)
{
  // digitalWrite(51, LOW);
  // digitalWrite(50, HIGH);
  // analogWrite(9, 255);
  digitalWrite(this->motorPinA, LOW);
  digitalWrite(this->motorPinB, HIGH);
  analogWrite(this->speedPWMPin, this->RPM2PWD(RPM));
  // Serial.println(this->RPM2PWD(RPM));
}

// rotate motor backwards
void MotorController::rotateMotorBackwards(int RPM = 30)
{
  digitalWrite(this->motorPinA, HIGH);
  digitalWrite(this->motorPinB, LOW);
  analogWrite(this->speedPWMPin, this->RPM2PWD(RPM));
}

// stop motor from rotating
void MotorController::stopMotorRotation(void)
{
  digitalWrite(this->motorPinA, LOW);
  digitalWrite(this->motorPinB, LOW);
  analogWrite(this->speedPWMPin, 0);
}

int MotorController::calculateRPM(void)
{
  // encoderValue = 0;
  speedMillis = millis();
  // delay(100);
  // long int currentMillis = millis();
  // Serial.print("encoder vlue: ");
  // Serial.print(encoderValue);
  int rpm = (int)(encoderValue * 60.0 / ((speedMillis - previousSpeedMillis) / 1000.0) / ENCODEROUTPUT);

  // Serial.print("Delta: ");
  // Serial.print(speedMillis - previousSpeedMillis);
  // Serial.print("Motor Speed: ");

  // Serial.print(rpm);

  encoderValue = 0;

  previousSpeedMillis = speedMillis;
  // encoderValue = 0;
  // Serial.print(" RPM before processing is: ");
  // Serial.print(rpm);
  // Serial.print(" PWM is: ");
  // Serial.print(this->RPM2PWD(rpm));
  return rpm;
}

void MotorController::setSpeed(int RPM)
{
  this->Input = RPM;
}
