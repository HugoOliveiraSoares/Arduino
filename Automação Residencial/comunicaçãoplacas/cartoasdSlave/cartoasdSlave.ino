#include "SoftwareSerial.h"
SoftwareSerial blackBoardMaster(2,3); // (RX, TX)
#define ledPin 16 // numero do pino onde o LED esta conectado
void setup() {
  blackBoardMaster.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (blackBoardMaster.available() > 0){
    // le o byte recebido
    int received = blackBoardMaster.read();

    // se o byte recebido corresponde ao caractere '0'(48) apaga o LED
    if (received == '0'){
      digitalWrite(ledPin, LOW);
    }
  if (received == '1'){
        digitalWrite(ledPin,HIGH);
      }
  }
}
