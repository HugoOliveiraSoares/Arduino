 #define ledPin 13 //led no pino 13
 #define Botao 2 //botao no pino 2
 int EstadoBotao = 0; //Variavel para ler o status do pushbutton

 void setup() 
 {
   pinMode(ledPin, OUTPUT); // pino do led sera saida
   pinMode(Botao, INPUT); // pino com botao sera entrada
 }

 void loop() 
 {
  EstadoBotao = digitalRead(Botao); /*novo estado do botão vai ser igual ao que Arduino ler no pino onde está o botão. 
                                      Poderá ser ALTO (HIGH)se o botão estiver
                                      Pressionado, ou BAIXO (LOW),se o botão
                                      estiver solto */
  if(EstadoBotao == HIGH){ // se botao estiver pressionado (high)
    digitalWrite(ledPin, HIGH); //acende o led do pino 13
  }
  else{        //se nao estiver presionado
    digitalWrite(ledPin, LOW); //deixa o led do pino 13 apagado
  }
 }
