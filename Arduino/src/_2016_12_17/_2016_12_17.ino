#include<Servo.h>
Servo my;
void setup() {
  // put your setup code here, to run once:
my.attach(8,600,2400);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 600; i <= 2400; i+=100){
    my.writeMicroseconds(i); // 直接以脈衝寬度控制

    delay(300);
  }
  for(int i = 2400; i >= 600; i-=100){
    my.writeMicroseconds(i);

    delay(300);
  }
}
