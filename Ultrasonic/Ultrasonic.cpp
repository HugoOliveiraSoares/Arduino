#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(int trigg, int echo)
{
  this->pin_trigger = trigg;
  this->pin_echo = echo;
  pinMode(pin_trigger, OUTPUT);
  pinMode(pin_echo, INPUT);
}

double Ultrasonic::dist_cm()
{
  digitalWrite(pin_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trigger, LOW);
  unsigned long microSec = pulseIn(pin_echo, HIGH);
  double distancia_cm = (microSec*0.0343)/2;

  if (distancia_cm == 0 || distancia_cm > 400) {
    return -1;
  } else {
    return distancia_cm;
  }
}
