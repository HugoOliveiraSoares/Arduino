#include <Ultrasonic.h>

Ultrasonic ultra(4,5);

float dist_cm;
long microsec;

void setup()
{

  Serial.begin(9600);

}

void loop()
{

  microsec = ultra.timing();

  dist_cm = ultra.convert(microsec, CM);

  Serial.print("Distancia: ");
  Serial.println(dist_cm);
  delay(1000);

}
