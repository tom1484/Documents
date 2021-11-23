const int led=13;
int sensorValue;
int sensorHigh=0;
int sensorLow=1023;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
digitalWrite(led, HIGH);
while(millis()<5000)
{
  sensorValue=analogRead(A0);
  if(sensorValue>sensorHigh)
  {
    sensorHigh=sensorValue;
  }
  if(sensorValue<sensorLow)
  {
    sensorLow=sensorValue;
  }
}
digitalWrite(led, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
  int pitch=map(sensorValue,sensorHigh,sensorLow,4000,50);
  tone(8,pitch);

}
