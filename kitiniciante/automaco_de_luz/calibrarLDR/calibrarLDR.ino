const int LDR = 0;
int ValorLido = 0;
const int LDR2 = 1;
int ValorLido2 = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  ValorLido = analogRead(LDR);
  ValorLido2 = analogRead(LDR2);
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(ValorLido);
  Serial.print("Valor lido pelo LDR2 = ");
  Serial.println(ValorLido2);
  delay(1000);
}
