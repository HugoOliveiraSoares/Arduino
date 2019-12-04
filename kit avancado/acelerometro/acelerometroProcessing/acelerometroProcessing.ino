#include <Wire.h>
#include <SFE_MMA8452Q.h>
MMA8452Q accel;
void setup()
{
Serial.begin(9600);
accel.init();
}
void loop()
{
if (accel.available()){
accel.read();
printOrientation();
delay(250);
}
}
void printOrientation()
{
byte pl = accel.readPL();
switch (pl)
{
case PORTRAIT_U:
Serial.print(0);
break;
case PORTRAIT_D:
Serial.print(1);
break;
case LANDSCAPE_R:
Serial.print(2);
break;
case LANDSCAPE_L:
Serial.print(3);
break;
case LOCKOUT:
Serial.print(4);
break;
}
}
