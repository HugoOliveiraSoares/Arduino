#ifndef SEG_CI4511
#define SEG_CI4511

#include "Arduino.h"

class Display
{
  private:
    int pin1, pin2, pin3, pin4; // Variaveis auxiliares

  public:
    Display(int pino1, int pino2, int pino3, int pino4);
    int numero(int num);
    int ponto(int pino, int val);
};

#endif
