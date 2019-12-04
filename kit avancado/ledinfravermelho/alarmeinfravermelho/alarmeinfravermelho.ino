const int buzzer = 12;
const int Receptor = A0;
int ValorSensor = 0;
void setup() {
pinMode(buzzer, OUTPUT);
}
void loop() {
ValorSensor = analogRead(Receptor);
if(ValorSensor > 1010) {
  digitalWrite(buzzer,HIGH);
  delay(1000); 
  }
   else{
   digitalWrite(buzzer, LOW);
  }

}
