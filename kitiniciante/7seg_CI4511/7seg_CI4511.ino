// Usando o CI CD4511

const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;

void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}

void loop()
{
  digitalWrite(a, LOW);//DIGITO 0   | 0000
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, HIGH);//DIGITO 1  | 0001
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, LOW);//DIGITO 2   | 0010
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, HIGH);//DIGITO 3  | 0011
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, LOW);//DIGITO 4   | 0100
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, HIGH);//DIGITO 5  | 0101
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, LOW);//DIGITO 6   | 0110
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, HIGH);//DIGITO 7  | 0111
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  
  delay(1000);
  
  digitalWrite(a, LOW);//DIGITO 8   | 1000
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  
  delay(1000);
  
  digitalWrite(a, HIGH); //DIGITO 9 | 1001
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  
  delay(1000);
}
