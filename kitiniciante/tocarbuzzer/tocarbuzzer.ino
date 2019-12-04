const int Buzzer = 12;
int tocar = 0;
void setup() {
 pinMode(Buzzer, OUTPUT);

}

void loop() {
  
while(tocar < 50){
  // do something repetitive 200 times
  digitalWrite(Buzzer,HIGH);
delay(250);
digitalWrite(Buzzer,LOW);
delay(100);
digitalWrite(Buzzer,HIGH);
delay(250);
digitalWrite(Buzzer,LOW);
delay(100);
digitalWrite(Buzzer,HIGH);
delay(250);
digitalWrite(Buzzer,LOW);
delay(100);
digitalWrite(Buzzer,HIGH);
delay(1000);
digitalWrite(Buzzer, LOW);
  delay(3000);
  }
}
