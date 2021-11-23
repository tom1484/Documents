#define RANGE 10
int i = 1;
int m = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  m = millis();
  if ((i*1000 + RANGE >= m) && (i*1000 - RANGE <= m)) {
    Serial.print(int(m/1000));
    Serial.println();
    i += 1;
  }
}
