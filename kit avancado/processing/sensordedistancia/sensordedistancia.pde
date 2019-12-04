import processing.serial.*;
Serial port;
int val;
int janela = 600;
int dimensao = 0;
void setup() {
println(Serial.list());
port = new Serial(this, Serial.list()[0], 9600);
size(600, 600); //criamos janela quadrada, de tamanho 600
rectMode(CENTER);
textFont(createFont("Arial", 16));
}
void draw() {
background(0);
if (port.available() > 0) {
val = port.read(); //recebo a variavel em decimal que representa um char conforme ASCII table
}
if (val == 'a') {
clear();
textSize(26);
textAlign(CENTER);
text("COLOQUE UM OBJETO A MENOS DE 20 CM DE DISTÂNCIA DO SENSOR", janela/2,janela/2, janela, 100);
} else
{
clear();
textSize(26);
textAlign(CENTER);
text("Distância: " + val + " cm", janela/2, janela);
rect(janela/2, janela/2, (-janela*0.05*val + janela), (-janela*0.05*val + janela));
//desenha o novo quadrado
}
}