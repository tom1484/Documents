//#include <SoftwareSerial.h>   // 引用程式庫
// 
//// 定義連接藍牙模組的序列埠
//SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
//char val;  // 儲存接收資料的變數
// 
//void setup() {
//  Serial.begin(9600);   // 與電腦序列埠連線
//  Serial.println("BT is ready!");
// 
//  // 設定HC-05藍牙模組，AT命令模式的連線速率。
//  BT.begin(38400);
//}
// 
//void loop() {
//  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
//  if (Serial.available()) {
//    val = Serial.read();
//    BT.print(val);
//  }
// 
//  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
//  if (BT.available()) {
//    val = BT.read();
//    Serial.print(val);
//  }
//}

#include <SoftwareSerial.h>

SoftwareSerial BT(8, 9);
char val;

//SpyderLeg leg;

void setup() {
  // put your setup code here, to run once:
//  leg.attach(8, 9);
  Serial.begin(9600);
  BT.begin(38400);
}
 
void loop() {
  // put your main code here, to run repeatedly:
//  for (int pos = -90; pos <= 90; pos ++) {
//    leg.write(INSIDE, pos);
//    delay(20);
//  }
//  for (int pos = 90; pos >= -90; pos --) {
//    leg.write(INSIDE, pos);
//    delay(20);
//  }
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }
}
