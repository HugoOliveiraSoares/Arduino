const int trig = 4;
const int echo = 5;

void setup() {
  
  Serial.begin (9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop() {
  long duracao;
  float distancia;
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duracao = pulseIn(echo, HIGH);
  
  distancia = duracao / 58;
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500);
}
