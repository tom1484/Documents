/*
*FileName:Serial_Between_Hardware _And_Software.ino
*Edit By Bear
*Web Site:http://blog.xuite.net/m0923678421/development/438845672
*Youtube:https://www.youtube.com/watch?v=sqLP36zr-CE
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(12,13);
String getword="";
bool getedH=0;
bool getedS=0;
void setup()  
{
  Serial.begin(115200);
  Serial.println("Hardware Read!!");

  mySerial.begin(9600);
  mySerial.println("Software Read!!");
}

void loop()
{
//get message from software serial to hardware serial.
  while (mySerial.available())
  {
    getedS=1;
    getword+=(char)mySerial.read();
    delay(5);
  }
  if(getedS)
  {    
    Serial.println(getword);
    getword="";
    getedS=0;
  }
  
//get message from hardware serial to software serial.
  while (Serial.available()){
    getedH=1;
    getword+=(char)Serial.read();
    delay(5);
  }
if(getedH)
  {    
    mySerial.println(getword);
    getword="";
    getedH=0;
  }    
}
