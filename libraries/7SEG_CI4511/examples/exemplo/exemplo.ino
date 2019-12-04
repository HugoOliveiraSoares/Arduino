/* Autor: Hugo Oliveira Soares
 *  Data: 19/07/2019
 *  
 *  Bibliteca para display de 7 segmentos usando o CI4511
 *  CI4511: Conversor BCD(binary-coded-decimal)
 * 
 * A bliblioteca ja define os pinos como SAIDA (OUTPUT)
 * 
*/

#include <7SEG_CI4511.h>

// Pinos que representam os 4 bits de entrada do CI
const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;

// Ponto do display(sem ligação com o CI, ligado direto no Arduino)
const int p = 10;

// Instancia a classe Display 
Display seg(a,b,c,d);

void setup() 
{

}

void loop() 
{
  seg.numero(0);    // número O
  delay(1000);  // Delay
  seg.numero(1);    // número 1
  delay(1000);  // Delay
  seg.numero(2);    // número 2
  delay(1000);  // Delay
  seg.numero(3);    // número 3
  delay(1000);  // Delay
  seg.numero(4);    // número 4
  delay(1000);  // Delay
  seg.numero(5);    // número 5
  delay(1000);  // Delay
  seg.numero(6);    // número 6
  delay(1000);  // Delay
  seg.numero(7);    // número 7
  delay(1000);  // Delay
  seg.numero(8);    // número 8
  delay(1000);  // Delay
  seg.numero(9);    // número 9
  delay(1000);  // Delay
  seg.ponto(p, 1);  // Ponto do display ligado
  delay(500);  // Delay
  seg.ponto(p, 0);  // Ponto do display desligado
  delay(500);  // Delay
  
}
