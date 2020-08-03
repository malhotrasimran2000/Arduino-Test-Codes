#include <BotBase.h>
#include <FourSBase.h>


int PWM_pins[] = {7,6,5,4};    // List of PWM pins
int DIR_pins[] = {8,9,10,11}; // List of DIR pins
bool reverseDIRs[] = {false, false, false, false};

float trans_vel = 0;
float angle = 0;
float ang_vel = 0;

FourSBase Base;

void setup()
{
  Serial.begin(9600);
  Base.debugger.Initialize("FourSBase", &Serial, DEBUG);
  Base.AttachPins(PWM_pins, DIR_pins, reverseDIRs);   // Attach pins for the motor driver
}

void loop()
{
  while (Serial.available())
  {
    switch (Serial.read()) {
      case 'P':
        trans_vel = Serial.parseInt();
        break;
      case 'A':
        angle = Serial.parseInt();
        break;
      case 'W':
        ang_vel = Serial.parseInt();
        break;
      case 'M':
        Base.Move(trans_vel, angle, ang_vel);
        delay(Serial.parseInt() * 1000);
        break;
      default:
        Base.Move(0, 0, 0);
    }
  }
}
