#include <Ultrasonic.h>


Ultrasonic::Ultrasonic(int trigg, int echo)
{

  this->pin_trigger = trigg;
  this->pin_echo = echo;
  pinMode(pin_trigger, OUTPUT);
  pinMode(pin_echo, INPUT);
}

long Ultrasonic::timing()
{
  digitalWrite(pin_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trigger, LOW);
  unsigned long microSec = pulseIn(pin_echo, HIGH);
  return microSec;
}

long Ultrasonic::convert(long t, int sys)
{

   float dist_cm = (t *0.0343)/2;
   float dist_inc = t / 74 / 2;
   if (sys)
   {
     if(dist_cm < 0 || dist_cm > 400)
      return -1.0;
     else
      return dist_cm;
   }
  else
    return dist_inc;
}
