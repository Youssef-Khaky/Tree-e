#include "Arduino.h"
class MotorController
{
    int motorPinA;
    int motorPinB; 
    int encoderPinA;
    int encoderPinB;
    int PWMSpeedPid;
    int LUT[36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66, 71, 73, 78, 84, 88, 93, 97, 105, 109, 120, 128, 134, 147, 160, 171, 194, 216, 240, 249, 255, 255, 255, 255, 255, 255};

public:
    MotorController(int motorPinA, int motorPinB, int encoderPinA, int encoderPinB);
    void rotateMotorForward(void);
    void rotateMotorBackwards(void);
    void stopMotorRotation(void);
    int RPM2PWD(int RPM);
};

#endif
