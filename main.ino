

#include <linearActuatorLibrary.h>

//#include <PIDController.h>

#include <MotorController.h>
#include <PID_v1.h>

#define FRMotorPinA 51
#define FRMotorPinB 50
#define FRMotorEnPinAInterrupt 3
#define FRMotorPWM 9

#define FLMotorPinA 48
#define FLMotorPinB 49
#define FLMotorEnPinAInterrupt 2
#define FLMotorPWM 10

MotorController backLeft(50, 51, 19, 22, 11);
MotorController frontLeft(52, 53, 2, 22, 10);
MotorController frontRight(22, 23, 3, 22, 9);
MotorController backRight(24, 25, 18, 22, 8);

long previousMillis = 0;
void setup()
{
  Serial.begin(9600);
  //whenever FRMotorEnPinA has a rising edge, run subroutine
  //  attachInterrupt(digitalPinToInterrupt(FRMotorEnPinAInterrupt), updateEncoder, RISING);
  //  frontRight.rotateMotorForward(30);
}

void loop()
{
  //    frontRight.Input = frontRight.calculateRPM();
  if ((millis() - previousMillis) > 20000)
  {
    previousMillis = millis();
  }
  frontRight.rotateMotorForward(255);
  frontLeft.rotateMotorForward(255);
  backRight.rotateMotorForward(255);
  backLeft.rotateMotorForward(255);
  delay(5000);
  frontRight.stopMotorRotation();
  frontLeft.stopMotorRotation();
  backRight.stopMotorRotation();
  backLeft.stopMotorRotation();
  delay(2000);
  frontRight.rotateMotorBackwards(255);
  frontLeft.rotateMotorBackwards(255);
  backRight.rotateMotorBackwards(255);
  backLeft.rotateMotorBackwards(255);
  delay(5000);
  frontRight.stopMotorRotation();
  frontLeft.stopMotorRotation();
  backRight.stopMotorRotation();
  backLeft.stopMotorRotation();
  delay(2000);
}

//void updateEncoder()
//{
//  frontRight.encoderValue++;
//}