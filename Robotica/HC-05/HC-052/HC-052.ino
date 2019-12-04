#include "SoftwareSerial.h" // Inclui a biblioteca SoftwareSerial
SoftwareSerial cel(2,3); // (RX, TX)

void setup() {
  Serial.begin(9600);
  cel.begin(9600);

}

void loop() {

  if (cel.available()>0)
  {
    char b = cel.read();
  
    Serial.println(b);
    delay(50);
  }

}
