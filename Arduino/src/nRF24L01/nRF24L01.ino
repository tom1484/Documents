#include <RF24.h>
#include <SPI.h>

RF24 rf24(3, 4); // CE腳, CSN腳
const byte addr[] = "1Node";
const char msg[] = "Happy Hacking!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  rf24.begin();
  rf24.setChannel(83);       // 設定頻道編號
  rf24.openWritingPipe(addr); // 設定通道位址
  rf24.setPALevel(RF24_PA_MIN);   // 設定廣播功率
  rf24.setDataRate(RF24_250KBPS); // 設定傳輸速率
  rf24.stopListening();       // 停止偵聽；設定成發射模式
  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!rf24.write(&msg, sizeof(msg))){
    Serial.println("It didn't work");
  }else{
    Serial.println("IT DID WORK");
  }
  rf24.printDetails();
  Serial.println("Lap");
  delay(1000);
}
