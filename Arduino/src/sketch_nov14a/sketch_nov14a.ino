#include<SoftwareSerial.h>

SoftwareSerial BT(8, 9);

void setup() {
  // put your setup code here, to run once:
  BT.begin(38400);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    BT.write(Serial.read());
  }
  if (BT.available()) {
    Serial.write(BT.read());
  }
}
