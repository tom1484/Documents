
#include <Servo.h> 
 
Servo myservo;  
 
int pos = 0;    
//初始化
void setup() 
{ 
  myservo.attach(9);  
} 
 
//主循环
void loop() 
{ 
    for(pos=0;pos<=180;pos+=10){
    myservo.write(pos);  
    delay(20); 
    }   
    for(pos=180;pos>=0;pos-=10){
    myservo.write(pos);  
    delay(20); 
    }
} 
