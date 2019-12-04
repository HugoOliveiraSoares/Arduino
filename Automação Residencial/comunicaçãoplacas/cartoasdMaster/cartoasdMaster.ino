#include <SPI.h>
#include <SD.h>
#include "SoftwareSerial.h"

// Cria uma serial em software 
SoftwareSerial blackBoardSlave(2,3); // (RX, TX)

File myFile;

void setup() {
 Serial.begin(9600);
 // inicia a serial em software com uma taxa de 9600 bit/s
  blackBoardSlave.begin(9600);

  Serial.print("Iniciando cartao SD...");

  if (!SD.begin(4)) {
    Serial.println("ERRO ao iniciar!");
    blackBoardSlave.write('1');
    return;
  }
  Serial.println("SUCESSO ao iniciar.");
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
     Serial.print("Writing to test.txt...");
      myFile.println("testing 1, 2, 3.");
      // close the file:
      myFile.close();
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }

  myFile = SD.open("test.txt");
    if (myFile) {
      blackBoardSlave.println("test.txt:");
      Serial.println("test.txt:");
  
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        blackBoardSlave.write(myFile.read());
        Serial.write(myFile.read());
      }
  myFile.close();
    } else {
      // if the file didn't open, print an error:
     Serial.println("error opening test.txt");
    }

}

void loop() {
  // put your main code here, to run repeatedly:

}
