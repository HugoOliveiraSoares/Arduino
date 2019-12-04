#ifndef ULTRASONIC_H_INCLUDED
#define ULTRASONIC_H_INCLUDED

#include <Arduino.h>

class Ultrasonic
{
  private:
    int pin_trigger;
    int pin_echo;

  public:
    Ultrasonic(int trigg, int echo);
    double dist_cm();

};

#endif
