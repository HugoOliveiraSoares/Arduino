const int lm35 = A0;
const int LDR = A1;

int luz = 0;
float temperatura = 0;

void setup() {
Serial.begin(9600);
analogReference(INTERNAL);  

}

void loop() {
  luz = analogRead(LDR);
  luz = map(luz, 0, 1023, 0, 100);
  delay(500);
  temperatura = analogRead(lm35);
  temperatura = temperatura *  0.1075268817204301;

Serial.print("Temperatura = ");   
Serial.print(temperatura);   
Serial.println(" *C");   

Serial.print("| Luminusidade = ");
Serial.print(luz);    
delay(500); 
}
