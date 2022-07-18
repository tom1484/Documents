#include <Arduino.h>
#line 1 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino"
#include "SpyderLeg.h"
#include "Bluetooth.h"

SpyderLeg leg[4];

//Bluetooth BT;
Bluetooth BT;

int com;

#line 11 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino"
void setup();
#line 24 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino"
void loop();
#line 11 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
     
  leg[0].attach(2, 3);
  leg[1].attach(4, 5);
  leg[2].attach(6, 7);
  leg[3].attach(8, 9);
  
  BT.attach(10, 11);
 
}
 
void loop() {
  com = BT.read();
leg[0].write(INSIDE,0);
   leg[0].write(OUTSIDE,0);
   leg[3].write(INSIDE,0);
   leg[3].write(OUTSIDE,0);
leg[1].write(INSIDE,-100);
   leg[1].write(OUTSIDE,100);
   leg[2].write(INSIDE,100);
   leg[2].write(OUTSIDE,-100);
   delay(1000);
   leg[0].write(INSIDE,-100);
   leg[0].write(OUTSIDE,-100);
   leg[3].write(INSIDE,100);
   leg[3].write(OUTSIDE,100);
   leg[1].write(INSIDE,0);
   leg[1].write(OUTSIDE,0);
   leg[2].write(INSIDE,0);
   leg[2].write(OUTSIDE,0);
   delay(1000);

  if (com == 1) {
    
  } 
  else if (com == 2) {
    
  }
  else if (com == 3) {
    
  }
  else if (com == 4) {
    
  }
}

