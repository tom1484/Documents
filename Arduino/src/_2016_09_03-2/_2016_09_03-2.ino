int note[]={
262,294,330,394};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sounder=analogRead(A0);
Serial.println(sounder);
if(sounder > 480 && sounder < 520){
  tone(8,4000);
}
else if(sounder > 390 && sounder < 430){
  tone(8,note[2]);
}
}
