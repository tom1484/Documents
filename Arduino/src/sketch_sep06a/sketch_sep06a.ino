#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);
  servo.write(75);
}

void loop() {
  // put your main code here, to run repeatedly:

}
