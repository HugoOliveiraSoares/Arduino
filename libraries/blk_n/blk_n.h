#ifndef BLK_N
#define BLK_N

#include "Arduino.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


class blk_n
{
  private:
    int pin;

  public:
    blk_n(int pino);
    void blk_led(int ms);
    void blk_vel(char vel[15]);

};

#endif
