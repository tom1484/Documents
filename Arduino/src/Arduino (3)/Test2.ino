#include <SoftwareSerial.h>

SoftwareSerial BT(A0, A1);
char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("BT is ready!");
  
  BT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
  }
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }
}
