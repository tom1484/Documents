#include <Servo.h> 
Servo myservo;
int pos=0;
void setup() {
  // put your setup code here, to run once:
myservo.attach(8);
Serial.begin(9600);
}
void loop()
{
 if(Serial.available())
 {
   String value = Serial.readStringUntil('\n');
   Serial.println(value);
   if(value == "right")
   {
     pos += 1;
     myservo.write(pos);
     delay(15);
   }
   else if(value == "left")
   {
     pos -= 1;
     myservo.write(pos);
     delay(15);
   }
  
 }
}
