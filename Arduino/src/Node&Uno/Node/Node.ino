#include <SoftwareSerial.h>
SoftwareSerial myPort(4, 5);
char p[] = "test";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myPort.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  myPort.write(p);
  delay(1000);
}
