#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9); // RX | TX

const int forward = 2, back = 3, left = 4, right = 5;
int com;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);

  pinMode(forward, INPUT);
  pinMode(back, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
}

void loop() {
  if (digitalRead(forward)) com = 1;
  else if (digitalRead(back)) com = 2;
  else if (digitalRead(left)) com = 3;
  else if (digitalRead(right)) com = 4;
  else com = 0;

  BT.write(com);
}
