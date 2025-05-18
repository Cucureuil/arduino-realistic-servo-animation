#include "SmoothServo.h"
#include <Arduino.h>

SmoothServo::SmoothServo(int delay) : Servo()
{
    customDelay = delay;
}

void SmoothServo::smoothWrite(int value, int delay)
{
    int delayToApply = this->customDelay;
    if (delay > -1)
    {
        delayToApply = delay;
    }

    int i = this->read();
    unsigned long startTime = millis();
    while (i != value)
    {
        if (millis() - startTime > delayToApply)
        {
            i += i < value ? 1 : -1;

            this->write(i);
            startTime = millis();
        }
    }
}
