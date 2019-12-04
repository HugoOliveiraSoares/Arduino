int ValorLido = 0;
int nota = 0;
const int Buzzer = 5;
void setup() {
}

void loop() {
   ValorLido = analogRead(A0);
   nota = map(ValorLido,3540,0, 4620,5000);
   tone(Buzzer,nota,20);
   delay(10);
}
