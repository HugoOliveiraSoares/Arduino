// SENSOR > 300 ESCURO
// SENSOR < 300 CLARO

#define M1 5 //velocidade motor A - de 0 a 255, Motor direito
#define M2 6 // velocidade motor B - de 0 a 255, Motor esquerdo
#define S1 0 // Sensor ligado no pino 0 - direito
#define S2 1 // Sensor ligado no pino 1 - esquerdo
#define led 13

void setup(){

  pinMode(M1, OUTPUT); // Motor como saida
  pinMode(M2, OUTPUT); // Motor como saida
  pinMode(S1, INPUT); // sensor como entrada (leitura)
  pinMode(S2, INPUT); // sensor como entrada (leitura)
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);

}

void loop(){

  if(analogRead(S1) < 500  && analogRead(S2) < 500 ) // Se sensor1 e sensor2 lerem uma faixa escura o carro vai pra frente
  {
    analogWrite(M1, 90); // Velocidade
    analogWrite(M2, 90); // Velocidade
    digitalWrite(led, LOW);
  }

  if(analogRead(S1) > 400 && analogRead(S2) < 400 )// Se sensor1 ler uma faixa escura e sensor2 faixa clara o carro vai para a direita
  {
    analogWrite(M1, 100); // Velocidade
    analogWrite(M2, 0); // Velocidade
    // delay(5000);
    digitalWrite(led, HIGH);
  }

  if(analogRead(S1) < 400 && analogRead(S2) > 400 )// Se sensor1 ler uma faixa clara e sensor2 faixa escura o carro vai para a esquerda
  {
    analogWrite(M1, 0); // Velocidade
    analogWrite(M2, 100); // Velocidade
    // delay(5000);
    digitalWrite(led, HIGH);
  }

  if(analogRead(S1) > 500  && analogRead(S2) > 500 ) // Se sensor1 e sensor2 lerem uma faixa clara o carro para
  {
    analogWrite(M1, 0); // Velocidade
    analogWrite(M2, 0); // Velocidade
    digitalWrite(led, LOW);
  }
}
