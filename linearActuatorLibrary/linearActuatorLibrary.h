#ifndef linearActuatorLibrary_h
#define linearActuatorLibrary_h
#include "Arduino.h"

// library interface description
class linearActuatorLibrary
{
  int speedPin_PWM;
  int directionPin1_DIGITAL;
  int directionPin2_DIGITAL;

  public:
    linearActuatorLibrary(int directionPin1_DIGITAL, int directionPin2_DIGITAL, int speedPin_PWM);
    void dig(void);
    void reset(void);
    void stopMotor(void);
    void demoOne(void);

  private:
    void extend(void);
    void retract(void);
};

#endif


