#include "blk_n.h"

blk_n::blk_n(int pino)
{
  pinMode(pino, OUTPUT);
  pin = pino;
}

void blk_n::blk_led(int ms)
{

  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
  delay(ms);
}

void blk_n::blk_vel(char vel[10])
{

    if (vel == "rapido")
    {
      blk_led(500);
    }else if (vel == "medio")
    {
      blk_led(1000);
    } else if (vel == "lento")
    {
      blk_led(2000);
    }
}
