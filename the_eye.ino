// Include the servo library:
#include <Servo.h>

// Define the servo pin:
#define xAxisPin 3
#define yAxisPin 4

// Create a new servo object:
Servo xAxisServo, yAxisServo;

int servo_start = 20;
int servo_range = 160;
int servo_step = 1;
int step_sleep = 15;

int x0, y0, x1, y1 = 0;

int sleep_time = 3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Attach the Servo variable to a pin:
  xAxisServo.attach( xAxisPin);
  yAxisServo.attach( yAxisPin);
}

void loop() {
  // Tell the servo to go to a particular angle:
  // Sweep from 0 to servo_range
  for (int pos = servo_start; pos < servo_range; pos += servo_step) {
    xAxisServo.write(pos);
    delay(step_sleep);
  }

  // Sweep from servo_range to 0
  for (int pos = servo_range; pos > servo_start; pos -= servo_step) {
    xAxisServo.write(pos);
    delay(step_sleep);
  }

    // Sweep from 0 to servo_range
  for (int pos = servo_start; pos < servo_range; pos += servo_step) {
    yAxisServo.write(pos);
    delay(step_sleep);
  }

  // Sweep from servo_range to 0
  for (int pos = servo_range; pos > servo_start; pos -= servo_step) {
    yAxisServo.write(pos);
    delay(step_sleep);
  }
  
  // put your main code here, to run repeatedly:
  x1 = analogRead(1);   // Auslesen des Wertes, der an A1 anliegt.
  y1 = analogRead(A0);  // Auslesen des Wertes, der an A0 anliegt.

  if ((x0 != x1) || (y0 != y1)){
    x0 = x1;
    y0 = y1;
    Serial.print("X: ");      
    Serial.print(x0, DEC);
    Serial.print(" | Y:");
    Serial.print(y0, DEC);
    Serial.print("\n");
  }

  delay(sleep_time);
}
