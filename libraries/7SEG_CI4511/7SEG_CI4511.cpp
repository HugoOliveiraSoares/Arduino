#include "7SEG_CI4511.h"

Display::Display(int pino1, int pino2, int pino3, int pino4) // Define os pinos como saida
{
  pinMode(pino1, OUTPUT);
  pinMode(pino2, OUTPUT);
  pinMode(pino3, OUTPUT);
  pinMode(pino4, OUTPUT);
  pin1 = pino1;
  pin2 = pino2;
  pin3 = pino3;
  pin4 = pino4;
}

int Display::numero(int num) // Verifica qual numero a ser mostrado
{
  if (num == 0)
  {
    digitalWrite(pin1, LOW);   // DIGITO 0 | 0000
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);

  }else if (num == 1)
  {
    digitalWrite(pin1, HIGH);  // DIGITO 1 | 0001
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);

  }else if (num == 2)
  {
    digitalWrite(pin1, LOW);   // DIGITO 2 | 0010
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);

  } else if (num == 3)
  {
    digitalWrite(pin1, HIGH);   //DIGITO 3  | 0011
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);

  } else if (num == 4)
  {
    digitalWrite(pin1, LOW);   //DIGITO 4  | 0100
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);

  } else if (num == 5)
  {
    digitalWrite(pin1, HIGH);   //DIGITO 5  | 0101
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);

  }else if (num == 6)
  {
    digitalWrite(pin1, LOW);   //DIGITO 6  | 0110
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);

  } else if (num == 7)
  {
    digitalWrite(pin1, HIGH);   //DIGITO 7  | 0111
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);

  } else if (num == 8)
  {
    digitalWrite(pin1, LOW);   //DIGITO 8  | 1000
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);

  } if (num == 9)
  {
    digitalWrite(pin1, HIGH);   //DIGITO 9  | 1001
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
  }
}

int Display::ponto(int pino, int val) // Aciona o ponto
{
  pinMode(pino, OUTPUT);

  if (val == 1)
  {
    digitalWrite(pino, HIGH);
  }
  if (val == 0)
  {
    digitalWrite(pino, LOW);
  }

}
