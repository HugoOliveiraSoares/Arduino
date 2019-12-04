#include <ESP8266WiFi.h>;

#include <SPI.h>
#include <SD.h>

File site;

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

void setup() { 
 pinMode(pin, OUTPUT);
 Serial.begin(9600);
//Conectando a rede Wifi
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
 Serial.print("Iniciando o cartao SD!...");
  if (!SD.begin(4)) {
    Serial.println("ERRO ao iniciar o cartao SD!");
    return;
  }
  Serial.println("SUCESSO ao iniciar o cartao SD");
//Verificando se esta conectado,
  //caso contrario, espera um pouco e verifica de novo.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

  }

//Iniciando o servidor Web
  server.begin();

}
void loop() {
  //Verificando se o servidor esta pronto.
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  //Verificando se o servidor recebeu alguma requisicao
  while (!client.available()) {
    delay(1);
  }
//Obtendo a requisicao vinda do browser
  String req = client.readStringUntil('\r');
  
  //Sugestao dada por Enrico Orlando
  if(req == "GET /favicon.ico HTTP/1.1"){
      req = client.readStringUntil('\r');
  }
 client.flush();
  
  if (!SD.exists("Projeto IOT2.htm")) {

    Serial.println("ERRO - Projeto IOT.htm nao foi encontrado!");
      return;
    }

  Serial.println("SUCESSO - Encontrado arquivo Projeto IOT.htm.");
  site = SD.open("Projeto IOT2.htm");
            if (site) {
              while (site.available()) {
                client.write(site.read());
              }
              site.close();
            }
//Analisando a requisicao recebida para decidir se liga ou desliga a lampada
  if (req.indexOf("on") != -1)
  {
    digitalWrite(pin, LOW);
  }
  else if (req.indexOf("off") != -1)
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    //Requisicao invalida!
    client.stop();
  }

}
