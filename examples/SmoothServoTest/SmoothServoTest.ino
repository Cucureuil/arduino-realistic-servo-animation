#include <SmoothServo.h>

SmoothServo servo(5);

void setup()
{
    Serial.begin(9600);
    servo.attach(7);
    servo.write(90);
}

void loop()
{
    servo.smoothWrite(75);
    delay(3000);
    servo.smoothWrite(180, 8);
    delay(3000);
}
