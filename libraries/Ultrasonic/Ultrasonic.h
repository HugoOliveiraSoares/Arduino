#ifndef ULTRASONIC_H_INCLUDED
#define ULTRASONIC_H_INCLUDED

#include <Arduino.h>

#define CM 1
#define INC 0

class Ultrasonic
{
  private:
    int pin_trigger;
    int pin_echo;

  public:
    Ultrasonic(int trigg, int echo);
    long timing();
    long convert(long t, int sys);

};

#endif
