const int numLinhas = 4; //número de linhas do teclado
const int numColunas = 3; //número de colunas do teclado
const int debounce = 20; //tempo de pausa
const char teclado[numLinhas][numColunas] = { //definição do teclado
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}};
const int PinosLINHAS[numLinhas] = { 7, 2, 3, 5}; //pinos do Arduino que correspondem às linhas do teclado
const int PinosCOLUNAS[numColunas] = { 6, 8, 4}; //pinos do Arduino que correspondem às colunas do teclado
const char kNADA = 0; //constante que simboliza nenhuma tecla pressionada (deve ser diferente de todos os valores em teclado[][] - o 0 desta variável não é o 0 do teclado)
//---------------------------------------------------------------------------------
void setup(){
Serial.begin(9600); //inicializa a Serial
//configura as linhas como entradas com padrão em nível lógico alto
for(int linha = 0; linha < numLinhas; linha++){
pinMode(PinosLINHAS[linha], INPUT);
digitalWrite(PinosLINHAS[linha], HIGH); //habilita pull-up
}
//configura as colunas como saídas com padrão em nível lógico alto
for(int coluna = 0; coluna < numColunas; coluna++){
pinMode(PinosCOLUNAS[coluna], OUTPUT);
digitalWrite(PinosCOLUNAS[coluna], HIGH);
}
Serial.println("--- pressione uma tecla ---");
}
//---------------------------------------------------------------------------------
void loop(){
char tecla = TeclaPressionada();
if(tecla != kNADA){
Serial.print("Tecla pressionada: ");
Serial.println(tecla);
}
}
//Determina qual tecla foi pressionada
char TeclaPressionada(){
char tecla = kNADA; //atribui o valor padrão de retorno (nenhuma tecla pressionada)
boolean achou = false; //inicialmente considera que nenhuma tecla foi pressionada
for(int coluna = 0; coluna < numColunas; coluna++){
digitalWrite(PinosCOLUNAS[coluna], LOW); //muda o estado do pino
//varre as linhas procurando por uma tecla pressionada
for(int linha = 0; linha < numLinhas; linha++){
//lê linha pela primeira vez
if(digitalRead(PinosLINHAS[linha]) == LOW){ //tecla está pressionada
delay(debounce); //insere pausa para descartar ruídos
}
//lê linha pela segunda vez
if(digitalRead(PinosLINHAS[linha]) == LOW){ //tecla continua pressionada, portanto não é um ruído
while(digitalRead(PinosLINHAS[linha]) != HIGH); //espera soltar a tecla para retornar
tecla = teclado[linha][coluna]; //determina qual foi a tecla pressionada de acordo com o teclado definido
achou = true; //uma tecla foi pressionada
break; //sai da varredura das linhas
}
}
digitalWrite(PinosCOLUNAS[coluna], HIGH); //retorna o pino ao seu estado inicial

//se uma tecla foi pressionada, sai do laço for
if(achou){
break;
}
}
return tecla; //retorna a tecla pressionada (kNADA se nenhuma foi encontrada)
}
