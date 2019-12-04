const int buzzer = 11;
int tempo = 0;

void setup() 
{
    pinMode(buzzer, OUTPUT);
}

void loop() 
{
  for(int x=0;x<5;x++)
  {
    delay(1000);
    tempo++;
  }

  if(tempo >= 5)
    analogWrite(buzzer,30);

}
