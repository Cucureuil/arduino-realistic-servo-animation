#ifndef SMOOTHSERVO_H
#define SMOOTHSERVO_H

#include <Servo.h>

class SmoothServo : public Servo
{
public:
    SmoothServo(int delay = 0);
    void smoothWrite(int value, int delay = -1);

private:
    int customDelay;
};

#endif
