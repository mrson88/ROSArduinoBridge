#ifndef SERVOS_H
#define SERVOS_H
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

#define N_SERVOS 6

// This delay in milliseconds determines the pause 
// between each one degree step the servo travels.  Increasing 
// this number will make the servo sweep more slowly.  
// Decreasing this number will make the servo sweep more quickly.
// Zero is the default number and will make the servos spin at
// full speed.  150 ms makes them spin very slowly.
int stepDelay [N_SERVOS] = { 0, 0 ,0, 0, 0, 0}; // ms

// Pins
byte servoPins [N_SERVOS] = { 0, 1, 2 ,3, 4, 5};

// Initial Position
byte servoInitPosition [N_SERVOS] = { 90, 90, 90, 90, 90, 90 }; // [0, 180] degrees



class SweepServo
{
  public:
    SweepServo();
    void initServo(
        int servoPin,
        int stepDelayMs,
        int initPosition);
    void doSweep(int servo, int angle);
    void setTargetPosition(int servo_pin, int position);
    void getServo(int servo);

  private:
    int stepDelayMs;
    int currentPositionDegrees;
    int targetPositionDegrees;
    long lastSweepCommand;
};

SweepServo servos [N_SERVOS];

#endif
