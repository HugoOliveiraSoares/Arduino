import processing.serial.*;
PFont f;
Serial port; // Cria objeto para a classe Serial
int val; // Variável para guardar dados da vindos da porta serial
int[] values;
void setup()
{
size(660, 480); //cria uma tela de 640 x 480
//o comando abaixo abre a porta que a placa está conectada e usa a mesma velocidade (115200 bps)
port = new Serial(this, Serial.list()[0], 115200);
values = new int[width];
smooth();
f = createFont("Arial",16,true); // Arial, 16 point, anti-aliasing on
}
int getY(int val) {
return (int)(val / 1023.0f * height) - 1;
}
void draw()
{
while (port.available() >= 3) {
if (port.read() == 0xff) {
val = (port.read() << 8) | (port.read());
}
}
for (int i=0; i<width-1; i++)
values[i] = values[i+1];
values[width-1] = val;
background(0);
stroke(255);
for (int x=1; x<width; x++) {
line(width-x, height-1-getY(values[x-1]),
width-1-x, height-1-getY(values[x]));
text("Valor atual = ", 505, 460);
text(val, 590,460);
}
textFont(f,14); //aqui escrevemos as frases de valores mínimo e máximo
fill(255);
text("Nível máximo = 1023",20,20);
text("Nível mínimo = 0",20,460);
}