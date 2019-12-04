/*
  comandos:
    - w : para frente
    - s : para tras
    - d : direita
    - a : esuerda
    - f : for OFF

*/

const int motor = 5;
const int dir = 7;
byte b;

// ------------------------------------------------

void setup(){
  Serial.begin(9600);
  Serial.println("Start");
  
  pinMode(motor, OUTPUT);
  pinMode(dir, OUTPUT);
}

// ------------------------------------------------

void loop(){
  
  if(Serial.available()){
    b = Serial.read();
    
    switch(b){
      // Para frente-------------------------------
      case 'w':
      for(int i=0 ; i <= 255 ; i++){
       analogWrite(motor, b);
        digitalWrite(dir, HIGH);
         Serial.println("frente");
          delay(20);
    }
        break;
       
      // Para tras-------------------------------
      case 's':
        for(int i=255 ; i >= 0 ; i--){
        analogWrite(motor, b);
        digitalWrite(dir, LOW);
        Serial.println("tras");  
          delay(20);
        }
        break;
     
      // Off------------------------------------
      case 'f':
        digitalWrite(motor, LOW);
        Serial.println("OFF");
        break;
      default:
        Serial.println("nothing");
        break;
      }
  }
  
}
