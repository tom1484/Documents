#include <Servo.h>
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
Servo myservo;
Servo servo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
servo.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
val = map(val, 0, 1023, 0, 179);
Serial.println(val);
myservo.write(val);
servo.write(val);

}
