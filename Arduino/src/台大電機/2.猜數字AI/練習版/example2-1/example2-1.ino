void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a[100];
  for(int j=0;j<100;j++){
  a[j]=j;
  }
  Serial.print("a[41]=");
  Serial.println(a[41]);
  Serial.print("a[50]=");
  Serial.println(a[50]);

  int b[10000];
  for(int j=0;j<10000;j++){
  b[j]=j;
  }
  Serial.print("b[4124]=");
  Serial.println(b[4124]);
  Serial.print("b[5350]=");
  Serial.println(b[5350]);
}

void loop() {

}
