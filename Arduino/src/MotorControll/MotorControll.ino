#include <Servo.h>

Servo servo;
int v;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(8);
//  servo.writeMicroseconds(2000);
//  servo.write(0);
}

void loop() {

  if (Serial.available()) {
    v = Serial.parseInt();
    Serial.println(v);
    if (v != 0)
      servo.writeMicroseconds(v);
  }
  // put your main code here, to run repeatedly:
//  for (int i = 0; i <= 180; i ++) {
//    motor.write(i);
//    delay(20);
//  }
//  for (int i = 180; i >= 0; i --) {
//    motor.write(i);
//    delay(20);
//  }
}
