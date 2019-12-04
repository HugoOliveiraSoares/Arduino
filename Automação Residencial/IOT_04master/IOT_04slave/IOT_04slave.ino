#include "SoftwareSerial.h"

// Cria uma serial em software 
SoftwareSerial blackBoardSlave(2,3); // (RX, TX)

const int pin = 13;

void setup() {
  blackBoardSlave.begin(9600); 
  pinMode(pin, OUTPUT);

}

void loop() {
   if (blackBoardSlave.available() > 0){
    // le o byte recebido
    int received = blackBoardSlave.read();

    // se o byte recebido corresponde ao caractere '0'(48) apaga o LED
    if (received == '3'){
      digitalWrite(pin, LOW);
    }
    
    // se o byte recebido corresponde ao caractere '1'(49) acende o LED
    if (received == '2'){
      digitalWrite(pin,HIGH);
    }
  }

}
