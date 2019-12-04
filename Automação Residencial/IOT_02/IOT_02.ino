#include <ESP8266WiFi.h>
#include<SD.h>

File webFile;
//Nome da sua rede Wifi
const char* ssid = "nome_da_rede";

//Senha da rede
const char* password = "senha";

//IP do ESP (para voce acessar pelo browser)
IPAddress ip(192, 168, 0, 1);

//IP do roteador da sua rede wifi
IPAddress gateway();

//Mascara de rede da sua rede wifi
IPAddress subnet();

//Criando o servidor web na porta 80
WiFiServer server(80);

//Pino do NodeMCU que estara conectado ao rele
const int pin = 16; //Equivalente ao D2 no NodeMCU

//Funcao que sera executada apenas ao ligar o ESP8266
void setup() {
  //Preparando o pino, que esta lidago ao rele
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);

   Serial.begin(115200);
   Serial.print("Inicializando o cartão SD...");

  if (!SD.begin(4)) {
    Serial.println("ERRO-Falha ao iniciar!");
    return;
  }
  Serial.println("SUCESSO-Inicialização bem sucedida.");

  if(!SD.exists("Projeto IOT.htm")){
    Serial.println("ERRO-Arquivo não encontrado");
    return;
    }
    Serial.println("SUCESSO-Arquivo encontrado");
  
  //Conectando a rede Wifi
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  
  
  //Verificando se esta conectado,
  //caso contrario, espera um pouco e verifica de novo.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  //Iniciando o servidor Web
  server.begin();
}

//Funcao que sera executada indefinidamente enquanto o NodeMCU estiver ligado.
void loop() {
  //Verificando se o servidor esta pronto.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  //Verificando se o servidor recebeu alguma requisicao
  if (client) { 
     boolean currentLineIsBlank = true; 
     while (client.connected()) { 
       if (client.available()) { 
 
 
         char c = client.read(); 
 
         if (c == '\n' && currentLineIsBlank) { 
           client.println("HTTP/1.1 200 OK"); 
           client.println("Content-Type: text/html"); 
           client.println("Connection: close"); 
           client.println(); 
          
          webFile = SD.open("Projeto IOT.htm");
          if(webFile){
            while(webFile.available()){
              client.write(webFile.read());
              }
            }
            webFile.close();
         }
         break;
        
        if(c =='\n'){
        currentLineIsBlank = true;
        }
        else if (c !='\r'){
          currentLineIsBlank = false;
          }
        }
      }
  delay(2);
   client.stop();
   }
}
