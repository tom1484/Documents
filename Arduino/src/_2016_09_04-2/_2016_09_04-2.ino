#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(3,2);
long p=10000;
const int led=4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long sensorValue = capSensor.capacitiveSensor(30);
Serial.println(sensorValue);
if(sensorValue<p){
  digitalWrite(led, HIGH);
}
else{
  digitalWrite(led, LOW);
}
}
