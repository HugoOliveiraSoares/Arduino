#define led 13
#define buzzer 11
#define sensor 0

void setup()
{
  pinMode(led,    OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop()
{
  if(millis() < 10000)
  {
    if(analogRead(sensor) < 300)
    {
      digitalWrite(led, HIGH);
    }
    if(analogRead(sensor) > 300)
    {
      digitalWrite(led, LOW);
    }
  }
  if(millis() > 10000 && millis() < 25000)
  {
    digitalWrite(led, LOW);
    analogWrite(buzzer, 20);
  }
  if(millis() > 25000)
  {
    analogWrite(buzzer, 0);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    analogWrite(buzzer, 0);
    delay(500);
    analogWrite(buzzer, 50);
    delay(500);
    analogWrite(buzzer, 100);
    delay(500);
    analogWrite(buzzer, 150);
    delay(500);
    analogWrite(buzzer, 200);
    delay(500);
    analogWrite(buzzer, 250);
    delay(500);
    
  }

}

