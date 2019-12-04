#include <Servo.h>

Servo servo;

const int numLinhas = 4; // número de linhas do teclado
const int numColunas = 3; // número de colunas do teclado
const int debounce = 20; // tempo de pausa

const char teclado[numLinhas][numColunas] = { // definição do teclado(matriz)
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

const int PinosLINHAS[numLinhas] = { 7, 2, 3, 5}; // pinos do arduino que correspondem as linhas do teclado
const int PinosCOLUNAS[numColunas] = { 6, 8, 4}; // pinos do arduino que correspondem as colunas do teclado
// constante que simboliza nenhuma tecla pressionada (deve ser deferente de todos os valores em teclado[][] - o 0 do desta variavel não é o 0 do teclado)
const char kNADA = 0; 

void setup()
{
  servo.attach(9);
  Serial.begin(9600); // inicia a Serial

  // configura as linhas  como padrão em nivel lógico alto
  for (int linha = 0; linha < numLinhas; linha++) {
    pinMode(PinosLINHAS[linha], INPUT);
    digitalWrite(PinosLINHAS[linha], HIGH); // habilita pull-up
  }

  // configura as colunasj como saídas com padrão em lógico alto
  for (int coluna = 0; coluna < numColunas; coluna++)
  {
    pinMode(PinosCOLUNAS[coluna], OUTPUT);
    digitalWrite(PinosCOLUNAS[coluna], HIGH);
  }

  Serial.println("--- pressione uma tecla ---");

}

void loop() {
  
  char tecla = TeclaPressionada();

  if (tecla != kNADA)
  {
    Serial.print("Posicao do eixo do servo: ");

    if (tecla == '1')
    {
      servo.write(10);
      Serial.println("10 graus");
    }
    else if (tecla == '2')
    {
      servo.write(20);
      Serial.println("20 graus");
    }
    else if (tecla == '3') {
      servo.write(30);
      Serial.println("30 graus");
    }
    else if (tecla == '4') {
      servo.write(40);
      Serial.println("40 graus");
    }
    else if (tecla == '5') {
      servo.write(50);
      Serial.println("50 graus");
    }
    else if (tecla == '6') {
      servo.write(60);
      Serial.println("60 graus");
    }
    else if (tecla == '7') {
      servo.write(70);
      Serial.println("70 graus");
    }
    else if (tecla == '8') {
      servo.write(80);
      Serial.println("80 graus");
    }
    else if (tecla == '9') {
      servo.write(90);
      Serial.println("90 graus");
    }
    else if (tecla == '*') {
      servo.write(150);
      Serial.println("150 graus");
    }
    else if (tecla == '0') {
      servo.write(0);
      Serial.println("0 graus");
    }
    else if (tecla == '#') {
      servo.write(180);
      Serial.println("180 graus");
    }
  }
}

char TeclaPressionada() // Determina qual tecla foi pressionada 
{

  char tecla = kNADA; // atribui o valor padrão de retorno (nenhuma tecla precionada)
  boolean achou = false; // inicialmete considera que nenhuma tecla foi pressionada 
  
  for (int coluna = 0; coluna < numColunas; coluna++) {
    digitalWrite(PinosCOLUNAS[coluna], LOW); // muda o estado do pino
    //varre as linhas procurando por uma tecla precionada
    for (int linha = 0; linha < numLinhas; linha++) {
      // le linha pela primeira vez
      if (digitalRead(PinosLINHAS[linha]) == LOW) { //tecla esta pressionada
        delay(debounce); // pausa para descartar ruidos
      }//le linhas pela segunda vez
      if (digitalRead(PinosLINHAS[linha]) == LOW) {//tecla continua pressionada, não é um ruido
        while (digitalRead(PinosLINHAS[linha]) != HIGH);//espera soltar a tecla para retornar 
        tecla = teclado[linha][coluna]; //deternina qual foi a tecla precionada de acordo com o teclado definido
        achou = true; //uma tecla foi pressionada
        break;//sai da varredura das linhas 
      }
    }
    digitalWrite(PinosCOLUNAS[coluna], HIGH);// retorna o pino ao seu estado inicial

    // se uma tecla foi pressionada, sai do laço for
    if (achou) 
    {
      break;
    }
  }
  return tecla; // retorna a tecla pressionada (kNADA se nenhuma foi encontrada
  
} //fim do código
