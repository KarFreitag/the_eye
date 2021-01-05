#include "EyeServo.h"
#include "EyeJoystick.h"

# define range of the servos
int servo_start = 20;
int servo_end = 160;
int joystick_min = 0;
int joystick_max = 1023;

// Define the servo pin:
#define xAxisJoyPin A0
#define yAxisJoyPin 1
#define xAxisServoPin 3
#define yAxisServoPin 4

EyeServo * xAxisServo;
EyeServo * yAxisServo;
EyeJoystick joystick( xAxisJoyPin, yAxisJoyPin, joystick_min, joystick_max, joystick_min, joystick_max);

float x0, y0 = 0;

int sleep_time = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  xAxisServo = new EyeServo( xAxisServoPin, servo_start, servo_end);
  yAxisServo = new EyeServo( yAxisServoPin, servo_start, servo_end);
}

void loop() {
  // Tell the servo to go to a particular angle:
  
  x0 = joystick.getX();
  y0 = joystick.getY();

  xAxisServo->setPosition(x0);
  yAxisServo->setPosition(y0);

  Serial.print("X: ");      
  Serial.print(x0);
  Serial.print(" | Y:");
  Serial.print(y0);
  Serial.print("\n");

  delay(sleep_time);
}
