//#include <PIDController.h>

#include <MotorController.h>
#include <PID_v1.h>

#define FRMotorPinA 51
#define FRMotorPinB 50
#define FRMotorEnPinAInterrupt 3 
#define FRMotorPWM 9

//motor object
MotorController frontRight(51,50,3,8,9);
//pid object
PID myPID(&(frontRight.Input), &(frontRight.Output), &(frontRight.Setpoint),0.7,0,0.5, DIRECT);


long previousMillis = 0;
void setup() {
  Serial.begin(9600);
  //whenever FRMotorEnPinA has a rising edge, run subroutine 
  attachInterrupt(digitalPinToInterrupt(FRMotorEnPinAInterrupt), updateEncoder, RISING);
  frontRight.rotateMotorForward(30);
  frontRight.Setpoint = 20;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(0, 50);
  myPID.SetSampleTime(20);
//  delay(2000);
  Serial.print("here");
}

void loop() {
    frontRight.Input = frontRight.calculateRPM();
    if ((millis() - previousMillis) >20000){
          frontRight.Setpoint = 30;
          previousMillis = millis();
          if (frontRight.Setpoint <0){
            frontRight.Setpoint = 30;
          }
    }


    myPID.Compute();
    frontRight.rotateMotorForward(frontRight.Output);
//    Serial.print(" setpoint is: ");
//    Serial.print((int) frontRight.Setpoint);
//    Serial.print(" input is: ");
//    Serial.print((int) frontRight.Input);
//    Serial.print("    output is: ");
//    Serial.println((int) frontRight.Output);
    
//    Serial.print("Setpoint is: ");
    Serial.print((int) frontRight.Setpoint);
    Serial.print(" ");
    Serial.print((int) frontRight.Input);
    Serial.print(" ");
    Serial.println((int) frontRight.Output);

    
//    digitalWrite(51, LOW);
//    digitalWrite(50, HIGH);
//    analogWrite(9, frontRight.LUT[30]);
    delay(10);
}



void updateEncoder()
{
  frontRight.encoderValue++;
}