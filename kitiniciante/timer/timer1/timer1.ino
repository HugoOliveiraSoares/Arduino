int segundo = 0;
int minuto = 0;
const int Buzzer = 5;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
void setup() {
  pinMode(Botao1,INPUT);
  pinMode(Botao2,INPUT);
  pinMode(Botao3,INPUT);
  pinMode(Buzzer,OUTPUT);
  Serial.begin(9600);
  Serial.println("selecione o tempo do timer");
  Serial.println("Minutos:0");
  Serial.println("Segundos:0");
}

void loop(){
EstadoBotao1 = digitalRead(Botao1);
if (EstadoBotao1 == HIGH){
delay(250);
if (EstadoBotao1 == HIGH){
segundo++;
if(segundo>=60){
segundo=0;
}
Serial.print("Segundos: ");
Serial.println(segundo);
}
}
EstadoBotao2 = digitalRead(Botao2);
if (EstadoBotao2 == HIGH){
delay(250);
if (EstadoBotao2 == HIGH){
minuto++;
if(minuto>=60){
minuto=0;
}
Serial.print("Minutos: ");
Serial.println(minuto);
}
}
EstadoBotao3 = digitalRead(Botao3);
if (EstadoBotao3 == HIGH){
if((minuto==0) && (segundo==0)){
//nao faz nada
}
else{
Serial.println("START");
delay(1000);
if(segundo==0){
minuto--;
segundo=59;
}
for(int y = 0; y<segundo; y--){
if(minuto<10){
Serial.print("0");
Serial.print(minuto);
Serial.print(":");
}
else{
Serial.print(minuto);
Serial.print(":");
}
if(segundo<10){
Serial.print("0");
Serial.println(segundo);
}
else{
Serial.println(segundo);
}
segundo--;
if(segundo<0){
minuto--;
segundo=59;
}
delay(1000); //base de tempo de 1 segundo
//para deixar timer mais rápido, diminuir aqui
if((segundo<=0) && (minuto<=0)) {
Serial.println("ACABOU O TEMPO!");
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
break; //sai do loop for
}
}
Serial.println("Selecione o tempo do timer...");
}
}
}
