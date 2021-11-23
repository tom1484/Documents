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
//目前被按壓的狀態
bool defaultState = 0;
//紀錄按壓的時間
long counter = 0;
//輸入點或劃的數量
int len = 0;
//輸入的摩斯電碼，0為點，1為劃
int morseCode[] = {0, 0, 0, 0, 0, 0};
// 定義keypad物件
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);//每秒取樣9600次
}

//清除上次輸入的內容
void clearMorse() {
  for (int i = 0; i < 6; i++) {
    morseCode[i] = 0;
  }
  len = 0;
}

//將摩斯電碼解成字母
void decodeMorse() {
  switch (len) {
    case 0:
      return;
    case 1:
      if (morseCode[0] == 1) {
        Serial.println('T');
      } else {
        Serial.println('E');
      }
      return;
    case 2:
      switch (morseCode[0] + morseCode[1] * 2) {
        case 0:
          Serial.println('I');
          break;
        case 1:
          Serial.println('N');
          break;
        case 2:
          Serial.println('A');
          break;
        case 3:
          Serial.println('M');
          break;
      }
      return;
    case 3:
      switch (morseCode[0] + morseCode[1] * 2 + morseCode[2] * 4) {
        case 0:
          Serial.println('S');
          break;
        case 1:
          Serial.println('D');
          break;
        case 2:
          Serial.println('R');
          break;
        case 3:
          Serial.println('G');
          break;
        case 4:
          Serial.println('U');
          break;
        case 5:
          Serial.println('K');
          break;
        case 6:
          Serial.println('W');
          break;
        case 7:
          Serial.println('O');
          break;
      }
      return;
    case 4:
      switch (morseCode[0] + morseCode[1] * 2 + morseCode[2] * 4 + morseCode[3] * 8) {
        case 0:
          Serial.println('H');
          break;
        case 1:
          Serial.println('B');
          break;
        case 2:
          Serial.println('L');
          break;
        case 3:
          Serial.println('Z');
          break;
        case 4:
          Serial.println('F');
          break;
        case 5:
          Serial.println('C');
          break;
        case 6:
          Serial.println('P');
          break;
        case 8:
          Serial.println('V');
          break;
        case 9:
          Serial.println('X');
          break;
        case 11:
          Serial.println('Q');
          break;
        case 13:
          Serial.println('Y');
          break;
        case 14:
          Serial.println('J');
          break;
        default:
          Serial.println("decoding fail!");
      }
      return;
    case 5:
      switch (morseCode[0] + morseCode[1] * 2 + morseCode[2] * 4 + morseCode[3] * 8 + morseCode[4] * 16) {
        case 30:
          Serial.println('1');
          break;
        case 28:
          Serial.println('2');
          break;
        case 24:
          Serial.println('3');
          break;
        case 16:
          Serial.println('4');
          break;
        case 0:
          Serial.println('5');
          break;
        case 1:
          Serial.println('6');
          break;
        case 3:
          Serial.println('7');
          break;
        case 7:
          Serial.println('8');
          break;
        case 15:
          Serial.println('9');
          break;
        case 31:
          Serial.println('0');
          break;
        default:
          Serial.println("decoding fail!");
      }
      return;
  }
}

void loop()
{
  char key = kpd.getKey();
  //讀取按鍵狀態
  bool keyState = kpd.getState();
  //偵測是否有按下或放開的動作
  if (defaultState != keyState) {
    if (keyState == 1) {
      if ((millis() - counter) > 500) {
        decodeMorse();
        clearMorse();
      } else {
        Serial.print(' ');
      }
      counter = millis();
      defaultState = 1;
    } else {
      if (len == 6) {
        Serial.println("input too long!");
        clearMorse();
      }
      if ((millis() - counter) > 500) {
        Serial.print('_');
        morseCode[len] = 1;
      } else {
        Serial.print('.');
      }
      len += 1;
      counter = millis();
      defaultState = 0;
    }
  }
}
