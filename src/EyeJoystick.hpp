#ifndef EyeJoystick_hpp
#define EyeJoystick_hpp

#include <Arduino.h>

class EyeJoystick {
  int xPin, yPin;
  int xMin, xMax, yMin, yMax;

public:
  EyeJoystick(int xPin, int yPin, int xMin, int xMax, int yMin, int yMax){
    this->xPin = xPin;
    this->yPin = yPin;
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
  }
  
  float getX() {
    int joyPos = analogRead(xPin);
    return normPosition( joyPos, xMin, xMax);
  }

  float getY() {
    int joyPos = analogRead(yPin);
    return normPosition( joyPos, yMin, yMax);
  }
  
  private:
  float normPosition(int joyPos, int valMin, int valMax){
    return (float)(joyPos - valMin) / (float)(valMax - valMin) * 2.0f - 1.0f;
  }
};

#endif
