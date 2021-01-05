#include "EyeServo.h"

EyeServo::EyeServo(int pin, int servoStart, int servoEnd)
{
    this->pin = pin;
    this->servo.attach(pin);
    this->servoStart = servoStart;
    this->servoEnd = servoEnd;

    this->setPosition(0.0f);
}

EyeServo::~EyeServo() {}

void EyeServo::setPosition(float position)
{
    position = max(-1.0f, min(1.0f, position));
    int servoPos = calcServoPosition(position);
    this->servo.write(servoPos);
}

int EyeServo::calcServoPosition(float position)
{
    return (position + 1.0f) / 2.0f * (servoEnd - servoStart) + 20;
}