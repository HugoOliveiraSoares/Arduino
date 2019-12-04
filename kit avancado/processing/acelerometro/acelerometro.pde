import processing.serial.*;
Serial port;
int val;
char valor;
void setup() {
println(Serial.list());
port = new Serial(this, Serial.list()[0], 9600);
size(600, 600);
rectMode(CORNERS);
}
void draw() {
if (port.available() > 0) {
val = port.read(); //recebo a variavel em decimal que representa um char conforme ASCII
valor = char(val); //transformo em char
}
switch(valor){
case '0':
up(); //seta para cima
break;
case '1':
down(); //seta para baixo
break;
case '3':
right(); //seta para direita
break;
case '2':
left(); //seta para esquerda
break;
case '4':
flat(); //posicao normal
break;
}
}
void flat() {
clear();
ellipse(300, 300, 400, 400);
}
void up() {
clear();
rect(200, 600, 400, 300);
triangle(300, 0, 0, 300, 600, 300);
}
void down() {
clear();
rect(200, 0, 400, 300);
triangle(0, 300, 600, 300, 300, 600);
}
void right() {
clear();
rect(0, 200, 300, 400);
triangle(300, 0, 600, 300, 300, 600);
}
void left() {
clear();
rect(300, 200, 600, 400);
triangle(300, 0, 300, 600, 0, 300);
}