#include "SpyderLeg.h"
#include "Bluetooth.h"

SpyderLeg frontLeft, frontRight;
SpyderLeg midLeft, midRight;
SpyderLeg rearLeft, rearRight;

//Bluetooth BT;
Bluetooth BT;

char command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  frontLeft.attach(2, 3);
  midLeft.attach(4, 5);
  rearLeft.attach(6, 7);
  frontRight.attach(8, 9);
  midRight.attach(10, 11);
  rearRight.attach(12, 13);
  
  BT.attach(A0, A1);
}
 
void loop() {
  if (BT.available()) {
    command = BT.read();
    Serial.println(command);

    if (command == '1') {
      LegUp(midLeft);
      LegUp(frontRight);
      LegUp(rearRight);
      delay(100);
      LegForward(midLeft, true);
      LegForward(frontRight, false);
      LegForward(rearRight, false);
      delay(100);
      LegDown(midLeft);
      LegDown(frontRight);
      LegDown(rearRight);
      delay(200);
      
      LegUp(midRight);
      LegUp(frontLeft);
      LegUp(rearLeft);
      delay(100);
      LegForward(midRight, false);
      LegForward(frontLeft, true);
      LegForward(rearLeft, true);
      delay(100);
      LegDown(midRight);
      LegDown(frontLeft);
      LegDown(rearLeft);
      delay(200);
    
      LegBack(midLeft, true);
      LegBack(frontRight, false);
      LegBack(rearRight, false);
      LegBack(midRight, false);
      LegBack(frontLeft, true);
      LegBack(rearLeft, true);
      delay(200);
    }

    if (command == '2') {
      LegUp(midLeft);
      LegUp(frontRight);
      LegUp(rearRight);
      delay(100);
      LegBack(midLeft, true);
      LegBack(frontRight, false);
      LegBack(rearRight, false);
      delay(100);
      LegDown(midLeft);
      LegDown(frontRight);
      LegDown(rearRight);
      delay(200);
      
      LegUp(midRight);
      LegUp(frontLeft);
      LegUp(rearLeft);
      delay(100);
      LegBack(midRight, false);
      LegBack(frontLeft, true);
      LegBack(rearLeft, true);
      delay(100);
      LegDown(midRight);
      LegDown(frontLeft);
      LegDown(rearLeft);
      delay(200);
    
      LegForward(midLeft, true);
      LegForward(frontRight, false);
      LegForward(rearRight, false);
      LegForward(midRight, false);
      LegForward(frontLeft, true);
      LegForward(rearLeft, true);
      delay(200);
    }

    if (command == '3') {
      LegUp(midLeft);
      LegUp(frontRight);
      LegUp(rearRight);
      delay(100);
      LegBack(midLeft, true);
      LegForward(frontRight, false);
      LegForward(rearRight, false);
      delay(100);
      LegDown(midLeft);
      LegDown(frontRight);
      LegDown(rearRight);
      delay(200);
      
      LegUp(midRight);
      LegUp(frontLeft);
      LegUp(rearLeft);
      delay(100);
      LegForward(midRight, false);
      LegBack(frontLeft, true);
      LegBack(rearLeft, true);
      delay(100);
      LegDown(midRight);
      LegDown(frontLeft);
      LegDown(rearLeft);
      delay(200);
    
      LegForward(midLeft, true);
      LegBack(frontRight, false);
      LegBack(rearRight, false);
      LegBack(midRight, false);
      LegForward(frontLeft, true);
      LegForward(rearLeft, true);
      delay(200);
    }

    if (command == '4') {
      LegUp(midLeft);
      LegUp(frontRight);
      LegUp(rearRight);
      delay(100);
      LegForward(midLeft, true);
      LegBack(frontRight, false);
      LegBack(rearRight, false);
      delay(100);
      LegDown(midLeft);
      LegDown(frontRight);
      LegDown(rearRight);
      delay(200);
      
      LegUp(midRight);
      LegUp(frontLeft);
      LegUp(rearLeft);
      delay(100);
      LegBack(midRight, false);
      LegForward(frontLeft, true);
      LegForward(rearLeft, true);
      delay(100);
      LegDown(midRight);
      LegDown(frontLeft);
      LegDown(rearLeft);
      delay(200);
    
      LegBack(midLeft, true);
      LegForward(frontRight, false);
      LegForward(rearRight, false);
      LegForward(midRight, false);
      LegBack(frontLeft, true);
      LegBack(rearLeft, true);
      delay(200);
    }
  }
  
//  for (int i = 70; i <= 110; i ++) {
//    frontLeft.write(INSIDE, i);
//    delay(20);
//  }
//  for (int i = 110; i >= 70; i --) {
//    frontLeft.write(INSIDE, i);
//    delay(20);
//  }

//  frontLeft.write(INSIDE, 70);
//  delay(500);
//  frontLeft.write(INSIDE, 110);
//  delay(500);

//  for (int i = 60; i <= 90; i ++) {
//    frontLeft.write(OUTSIDE, i);
//    delay(20);
//  }
//  for (int i = 90; i >= 60; i --) {
//    frontLeft.write(OUTSIDE, i);
//    delay(20);
//  }
//  frontLeft.write(OUTSIDE, 50);
}

void LegUp(SpyderLeg& leg) {
  leg.write(OUTSIDE, 90);
}

void LegDown(SpyderLeg& leg) {
  leg.write(OUTSIDE, 50);
}

void LegForward(SpyderLeg& leg, bool reverse) {
  if (reverse) leg.write(INSIDE, 120);
  else leg.write(INSIDE, 60);
}

void LegBack(SpyderLeg& leg, bool reverse) {
  if (reverse) leg.write(INSIDE, 60);
  else leg.write(INSIDE, 120);
}

void LegStepForward(SpyderLeg& leg, bool reverse) {
  LegUp(leg);
  delay(200);
  LegForward(leg, reverse);
  delay(200);
  LegDown(leg);
}

void LegStepBack(SpyderLeg& leg, bool reverse) {
  LegUp(leg);
  delay(200);
  LegBack(leg, reverse);
  delay(200);
  LegDown(leg);
}
