#include <Arduino.h>

class EyeJoystick
{
    int xPin, yPin;
    int xMin, xMax, yMin, yMax;

public:
    EyeJoystick(int xPin, int yPin, int xMin, int xMax, int yMin, int yMax);
    float getX();
    float getY();

private:
    float normPosition(int joyPos, int valMin, int valMax);
};
