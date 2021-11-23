#define ledpin1 A1
#define ledpin2 A2

void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
}

void loop()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(300);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(100);
}
