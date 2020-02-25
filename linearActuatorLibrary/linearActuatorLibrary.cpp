#include "Arduino.h"
#include "linearActuatorLibrary.h" 

linearActuatorLibrary::linearActuatorLibrary(int directionPin1_DIGITAL, int directionPin2_DIGITAL, int speedPin_PWM)
{
    this->directionPin1_DIGITAL = directionPin1_DIGITAL;
    this->directionPin2_DIGITAL = directionPin1_DIGITAL;
    this->speedPin_PWM = speedPin_PWM;
    pinMode(speedPin_PWM, OUTPUT);
    pinMode(directionPin1_DIGITAL, OUTPUT);
    pinMode(directionPin1_DIGITAL, OUTPUT);
}

void linearActuatorLibrary::dig(void){
}

void linearActuatorLibrary::stopMotor(void)
{
  digitalWrite(this->directionPin1_DIGITAL, LOW);
  digitalWrite(this->directionPin2_DIGITAL, LOW);
}

void linearActuatorLibrary::reset(void){
    retract();
    delay(21000);
}

void linearActuatorLibrary::extend(void){
    digitalWrite(this->directionPin1_DIGITAL, HIGH);
    digitalWrite(this->directionPin2_DIGITAL, LOW);
}

void linearActuatorLibrary::demoOne()
{
    extend();
    delay(4800);
    retract();
    delay(5200);
}

void linearActuatorLibrary::retract(void){
    digitalWrite(this->directionPin1_DIGITAL, LOW);
    digitalWrite(this->directionPin2_DIGITAL, HIGH); 
}
