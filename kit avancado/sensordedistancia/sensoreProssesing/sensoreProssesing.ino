const int trig = 13;
const int echo = 12;
void setup() {
Serial.begin (9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
}
void loop() {
long duracao;
long distancia;
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duracao = pulseIn(echo, HIGH);
distancia = duracao / 58;
if(distancia >= 20){
Serial.print("a");
}else{
Serial.write(distancia);
}
delay(50);
}
