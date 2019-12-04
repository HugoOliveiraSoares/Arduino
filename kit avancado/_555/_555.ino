#include "oscilloscope.h"
#define ANALOG_IN 0
void setup() {
Serial.begin(115200);
}
void loop() {
int val = analogRead(ANALOG_IN);
writeOscilloscope(val);
delay(50);
}
