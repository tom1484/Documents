int o=0;
int p=5;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(10, o);
o += p;
if(o <= 0 || o >=255)
p *= -1;
delay(15);
}
