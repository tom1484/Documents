const int led=13;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
const int sensor = digitalRead(8);
if(sensor==HIGH){
  digitalWrite(led, HIGH);
  Serial.println(sensor);
  delay(10);
}
}
