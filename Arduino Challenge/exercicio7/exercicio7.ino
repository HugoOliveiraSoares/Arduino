const int led = 11;

void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  

}

void loop() 
{
  for(int x=0; x<250; x+=50)
  {
    analogWrite(led,x);
    Serial.println(x);
    delay(1000);   
  }
}
