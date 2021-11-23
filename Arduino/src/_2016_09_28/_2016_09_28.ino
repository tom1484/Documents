#include <Servo.h> 
Servo myservo;
int pos=0;
void setup() {
  // put your setup code here, to run once:
myservo.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
for(pos = 0; pos < 180; pos += 1)  // 从0度到180度运动 
  {                                                     // 每次步进一度
    myservo.write(pos);        // 指定舵机转向的角度
    delay(15);                       // 等待15ms让舵机到达指定位置
  } 
  for(pos = 180; pos>=1; pos-=1)   //从180度到0度运动  
  {                                
    myservo.write(pos);         // 指定舵机转向的角度 
    delay(15);                        // 等待15ms让舵机到达指定位置 
  } 
}
