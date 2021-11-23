const int _1=3;
const int _2=4;
const int _3=5;
const int _4=6;
const int _0=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(_1,OUTPUT);
  pinMode(_2,OUTPUT);
  pinMode(_3,OUTPUT);
  pinMode(_4,OUTPUT);
  pinMode(_0,OUTPUT);
digitalWrite(_2, LOW);
digitalWrite(_4, LOW);
digitalWrite(_3, LOW);
digitalWrite(_1, LOW);
digitalWrite(_0, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(_1, LOW);
digitalWrite(_0, HIGH);
delay(1000);
digitalWrite(_2, LOW);
digitalWrite(_1, HIGH);
delay(1000);
digitalWrite(_3, LOW);
digitalWrite(_2, HIGH);
delay(1000);
digitalWrite(_4, LOW);
digitalWrite(_3, HIGH);
delay(1000);
digitalWrite(_0, LOW);
digitalWrite(_4, HIGH);
delay(1000);
}
