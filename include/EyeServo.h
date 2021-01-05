#include <Arduino.h>
#include <Servo.h>

class EyeServo
{
    int pin;
    Servo servo;
    int servoStart, servoEnd;

public:
    EyeServo(int pin, int servoStart, int servoEnd);
    ~EyeServo();
    void setPosition(float position);

private:
    int calcServoPosition(float position);
};