#include<Servo.h>
Servo my;
void setup() {
  Serial.begin(9600);

my.attach(8,600,2400);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if (Serial.available())
  {
    String value;
    value = Serial.readStringUntil('\n');
    Serial.println(value);
    
    
  }
}





