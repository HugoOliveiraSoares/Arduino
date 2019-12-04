#include <Ultrasonic.h>

Ultrasonic ultra(4,5);

float dist_cm;

void setup()
{

  Serial.begin(9600);

}

void loop()
{

  dist_cm = ultra.dist_cm();

  Serial.print("Distancia: ");
  Serial.println(dist_cm);
  delay(1000);

}
