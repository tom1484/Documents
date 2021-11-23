#include <SoftwareSerial.h>
SoftwareSerial myPort(10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myPort.begin(115200);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (myPort.available()){
    char value = myPort.read();
    Serial.println(value);
  }
  if (Serial.available())
    myPort.write(Serial.read());
}
