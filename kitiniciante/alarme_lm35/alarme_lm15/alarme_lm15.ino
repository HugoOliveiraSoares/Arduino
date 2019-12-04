const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int Buzzer = 12;
void setup() {
 analogReference(INTERNAL);
 pinMode(Buzzer, OUTPUT);
}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  if(temperatura > 32){ // alarme dispara
  digitalWrite(Buzzer, HIGH);
  }
  else{
   digitalWrite(Buzzer, LOW);
  }
}
