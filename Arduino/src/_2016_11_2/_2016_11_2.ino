const int p=0;
int o=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  o=analogRead(p);
  Serial.println(o);
  delay(100);
}
