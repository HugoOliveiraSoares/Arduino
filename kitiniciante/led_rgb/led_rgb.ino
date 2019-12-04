#define RED 3
#define BLUE 5
#define GREEN 6

 int red = 255, green = 255, blue = 255;
 void setup() {
 pinMode (RED, OUTPUT);
 pinMode (BLUE, OUTPUT);
 pinMode (GREEN, OUTPUT);
}

void loop() {
  analogWrite (RED, red);
  analogWrite (BLUE, blue);
  analogWrite (GREEN, green);
}
