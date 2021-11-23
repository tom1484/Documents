#include <Keypad.h>

const byte ROWS = 4; // 共有四行
const byte COLS = 4; // 共有四列
// 指定按下按鍵時輸入的內容
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// 每列的腳位編號
byte rowPins[ROWS] = {2, 3, 4, 5};
// 每行的腳位編號
byte colPins[COLS] = {6, 7, 8, 9};

// 定義keypad物件
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);//每秒取樣9600次
}

void loop()
{
  char key = kpd.getKey();
  if (key) { //若有訊號才顯示內容
    Serial.println(key);
  }
}
