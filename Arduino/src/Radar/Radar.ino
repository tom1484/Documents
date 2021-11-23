#include <Servo.h>
const int trig = 8;
const int echo = 9;
int degree = 0;
int l=0;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
  myservo.attach(6);
}

void loop() {
  for(degree = 0; degree <= 180; degree += 1){
    distance();
    servo();
    Serial.write(l);
    Serial.print(degree);
    Serial.println('.');
    delay(20);
  }
  for(degree = 180; degree >= 0; degree -= 1){
    distance();
    servo();
    Serial.write(l);
    Serial.print(degree);
    Serial.println('.');
    delay(15);
  }  
}
void servo(){
  myservo.write(degree);
  
}
void distance(){
  float s = 0;
  long time = 0;
  digitalWrite(trig, 1);
  delayMicroseconds(15);
  digitalWrite(trig, 0);
  time = pulseIn(echo, HIGH);
  s = time/58.00;
  if(s<=100)
  l = s;
  s = 0;
  time = 0;
}
