const int pwm = 3;
const int pot = A0;
int ValorLidoPot_Real = 0;
int ValorLidoPot_Mapeado = 0;
int BarraLed[] = {
2, 4, 5, 6, 7, 8, 9, 10, 11, 12};
void setup(){
Serial.begin(9600);
pinMode(pwm, OUTPUT);
for(int i = 0; i <= 9; i++){
pinMode(BarraLed[i],OUTPUT);
}
for(int i = 0; i <= 9; i++){
digitalWrite(BarraLed[i],LOW);
}
}
void loop(){
ValorLidoPot_Real = analogRead(pot);
ValorLidoPot_Mapeado = map(ValorLidoPot_Real, 0, 1023, 0, 255);
analogWrite(pwm, ValorLidoPot_Mapeado);
Serial.println(ValorLidoPot_Mapeado);
for(int i = 0; i <= 9; i++){
if(ValorLidoPot_Mapeado > ((i+1)*25)){
digitalWrite(BarraLed[i], HIGH);
}
else{
digitalWrite(BarraLed[i], LOW);
}
}
}
