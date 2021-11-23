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
String show = "";
int oprand = 0;
char op = NULL;

void initialize() {
  show = "";
  oprand = 0;
  op = NULL;
}
void setup()
{
  Serial.begin(9600);//每秒取樣9600次
  initialize();
}
int getValue(String str) {
  int ans = 0;
  for (int i = 0; i < str.length(); i++) {
    ans += str[i] - '0';
    ans = ans * 10;
  }
  ans = ans / 10;
  //Serial.print("value = ");
  //Serial.println(ans);
  return ans;
}
int calculate(int num1, int num2, char op) {
  switch (op) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    case '/':
      return num1 / num2;
  }
}

void loop()
{
  char key = kpd.getKey();
  if (key) { //若有訊號才顯示內容
    switch (key) {
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        show += key;
        Serial.println(show);
        break;
      case 'A':
        if (op) {
          Serial.print(oprand);
          Serial.print(op);
          Serial.print(show);
          Serial.print('=');
          oprand = calculate(oprand, getValue(show), op);
          Serial.println(oprand);
          op = '+';
          show = "";
        } else {
          op = '+';
          oprand = getValue(show);
          show = "";
        }
        break;
      case 'B':
        if (op) {
          Serial.print(oprand);
          Serial.print(op);
          Serial.print(show);
          Serial.print('=');
          oprand = calculate(oprand, getValue(show), op);
          Serial.println(oprand);
          op = '-';
          show = "";
        } else {
          op = '-';
          oprand = getValue(show);
          show = "";
        }
        break;
      case 'C':
        if (op) {
          Serial.print(oprand);
          Serial.print(op);
          Serial.print(show);
          Serial.print('=');
          oprand = calculate(oprand, getValue(show), op);
          Serial.println(oprand);
          op = '*';
          show = "";
        } else {
          op = '*';
          oprand = getValue(show);
          show = "";
        }
        break;
      case 'D':
        if (op) {
          Serial.print(oprand);
          Serial.print(op);
          Serial.print(show);
          Serial.print('=');
          oprand = calculate(oprand, getValue(show), op);
          Serial.println(oprand);
          op = '/';
          show = "";
        } else {
          op = '/';
          oprand = getValue(show);
          show = "";
        }
        break;
      case '#':
        if (op) {
          Serial.print(oprand);
          Serial.print(op);
          Serial.print(show);
          Serial.print('=');
          Serial.println(calculate(oprand, getValue(show), op));
        }
        initialize();
    }
  }
}
