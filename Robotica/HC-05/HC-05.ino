char c;

void setup()
{
   pinMode(13,OUTPUT);
   pinMode(5,OUTPUT);
   Serial.begin(9600);
}

void loop()
{
   if (Serial.available()>0)
   {
     c = Serial.read() - '0';
     Serial.flush();
     digitalWrite(c,!digitalRead(c));
   }
 }
