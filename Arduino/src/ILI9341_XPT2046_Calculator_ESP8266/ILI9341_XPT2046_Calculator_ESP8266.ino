#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#include <Wire.h>  
#define TOUCH_CS_PIN D3
#define TOUCH_IRQ_PIN D2

#define TS_MINX 330
#define TS_MINY 213
#define TS_MAXX 3963
#define TS_MAXY 3890

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
XPT2046_Touchscreen ts(TOUCH_CS_PIN);

// The display also uses hardware SPI(D5,D6,D7), SD3, D4, D8
static uint8_t SD3 = 10;
#define TFT_CS SD3
#define TFT_DC D4
#define BL_LED D8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

char lastchar = ' ';
String input = "";
/*long Time = 0;
long millicount = 0;
int interval = 1000;
int screenTimout = 15;*/

bool screenTouched = false;

#define row1x 0
#define extray 48

#define boxHeight 48
#define boxWidth 45

#define fontWidth 16
#define fontWidthFull 18

int x, y = 0;

#define butRow 4
#define butCol 7

char button[butRow][butCol] = {
  {'7', '8', '9', '+', 'D', '<', '>'},
  {'4', '5', '6', '-', '(', '^', 'M'},
  {'1', '2', '3', 'X', ')', 'e', 'm'},
  {'C', '0', '=', '/', '.', 'A', 'W'}
};

int butColor[butRow][butCol] = {
  {ILI9341_WHITE, ILI9341_WHITE, ILI9341_WHITE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE}, 
  {ILI9341_WHITE, ILI9341_WHITE, ILI9341_WHITE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE}, 
  {ILI9341_WHITE, ILI9341_WHITE, ILI9341_WHITE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE}, 
  {ILI9341_RED  , ILI9341_WHITE, ILI9341_GREEN, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE}
};

#define textWidth 18

int cur = 0;
int off = 0;

void draw() {
  
  tft.fillScreen(ILI9341_BLACK);

  // print all buttons
  for (int i = 0; i < butRow; i ++) {
    for (int j = 0; j < butCol; j ++) {
      tft.drawRoundRect(row1x + j * boxWidth, extray + i * boxHeight, boxWidth, boxHeight, 8, butColor[i][j]);
      tft.setCursor((boxWidth - fontWidth) / 2 + row1x + (boxWidth * j), 12 + extray + (boxHeight * i));
      tft.setTextSize(3);
      tft.setTextColor(ILI9341_WHITE);
      tft.println(button[i][j]);
    }
  }

  // draw bar
  tft.drawRoundRect(row1x, 0, row1x + boxWidth * 7, 48, 8, ILI9341_ORANGE);
  tft.setCursor(4 + row1x, 12);

}

void resetBar() {
  
  tft.setCursor(4 + row1x, 12);
  tft.fillRect(2, 4, fontWidthFull * 17 + 3, 40, ILI9341_BLACK);

}

void resetAll() {

  resetBar();
  input = "";
  cur = 0;
  off = 0;

}

void setup() {

  pinMode(BL_LED, OUTPUT);
  digitalWrite(BL_LED, HIGH);
  Serial.begin(9600);
  Serial.println("Calculator");
  ts.begin();
  tft.begin();
  tft.setRotation(3);
  draw();
  tft.setCursor(4 + row1x, 12);

}

void loop() {
  
  if (ts.touched() && !screenTouched) {

    // read touchscreen
    TS_Point p = ts.getPoint();
    screenTouched = true;

    // get button
    lastchar = idButton(
      map(p.x, TS_MINX, TS_MAXX, 0, tft.width()), 
      map(p.y, TS_MINY, TS_MAXY, 0, tft.height()));

    // delete one char
    if (lastchar == 'D')
      bDel();
    // calculate
    else if (lastchar == '=')
      bCalc();
    // calculate abs
    else if (lastchar == 'A')
      bAbs();
    // clear all
    else if (lastchar == 'C')
      bClear();
    // memory add
    else if (lastchar == 'M') {

    }
    // mamery minus
    else if (lastchar == 'm') {

    }
    // memory clear
    else if (lastchar == 'W') {

    }
    // move left
    else if (lastchar == '<') {
      if (cur > 0)
        tPrint(input, --cur);
    }
    // move right
    else if (lastchar == '>') {
      if (cur < input.length())
        tPrint(input, ++cur);
    }
    // insert char
    else
      insert(lastchar);

    // wait for release
    while (ts.touched())
      delay(10);
    screenTouched = false;
  }
}

void bDel() {

  // check if valid
  if (cur == 0)
    return ;
  // delete one char
  input.remove(--cur, 1);

  // print
  tPrint(input, cur);
}

void bCalc() {
  
  // calculate
  double ans = solve(input);
  input = doubleToString(ans);
  
  // set cursor and print
  tPrint(input, cur = input.length());
  
}

void bAbs() {

  // calculate
  double ans = solve(input);
  // abs
  if (ans < 0)
    ans *= -1;
  input = doubleToString(ans);

  // set cursor and print
  tPrint(input, cur = input.length());
}

void bClear() {
//  draw();
//  tft.fillRoundRect(0, 0, 320, 48, 8, ILI9341_BLACK);
//  tft.drawRoundRect(0, 0, 320, 48, 8, ILI9341_ORANGE);
  resetAll();
}

void insert(char c) {

  // insert into input
  input += ' ';
  for (int i = input.length() - 1; i > cur; i --)
    input[i] = input[i - 1];
  input[cur] = c;

  // move cursor and print
  tPrint(input, ++cur);
  
}

void tPrint(String str, int c) {
  
  // check if cursor exceeds borders
  if (c - off > 17)
    off++;
  else if (c - off < 0)
    off--;

  // clear bar and print
  resetBar();
  tft.print(input.substring(off, min(17 + off, int(input.length()))));
  tft.drawLine(3 + (c - off) * fontWidthFull, 5, 3 + (c - off) * fontWidthFull, 42, ILI9341_RED);

}

String intToString(int num) {

  String res = "";
  bool neg = false;

  // check if num is zero or negative
  if (num == 0)
    res = "0";
  if (num < 0) {
    neg = true;
    num *= -1;
  }

  // parsing
  while (num > 0) {
    res = char(num % 10 + '0') + res;
    num /= 10;
  }

  // add sign
  if (neg)
    res = '-' + res;

  return res;
  
}

String doubleToString(double num) {

  double c;
  num = modf(num, &c);

  String res = "0";
  bool neg = false;

  // check if c is zero
  if (c < 0.001 && c > -0.001)
    doubleToString(c);

  // check if num is zero or negative
  if (num == 0)
    res = "0";
  if (num < 0) {
    neg = true;
    num *= -1;
  }
  num *= 10;

  // parsing
  if (num > 0.001) {
    res += '.';
    for (int i = 0; i < 3 && num > 0.001; i ++) {
      res += char(int(num) + '0');
      num -= int(num);
      num *= 10;
    }
  }

  // add sign
  if (neg)
    res = '-' + res;

  return res;
  
}

int getNum(String &str, int startPos, double &res) {

  // check if num is zero or negative
  bool neg = false;
  if (str[startPos] == '-') {
    neg = true;
    startPos++;
  }

  res = 0;
  int endPos = startPos, dotPos = startPos;

  // parsing
  for (; endPos < str.length(); endPos ++) {
    char c = str[endPos];
    if ((c >= '0' && c <= '9') || c == '.') {
      if (c != '.')
        res = res * 10 + (c - '0');
      else
        dotPos = endPos;
    }
    else
      break;
  }

  // handle doubleing number
  if (dotPos > startPos)
    for (int i = 0; i < endPos - dotPos - 1; i ++)
      res /= 10;

  // add sign
  if (neg)
    res *= -1;

  return endPos;
  
}

int getBracket(String &str, int startPos, String &res) {

  res = "";
  String stk = "";
  int endPos = startPos;

  // parsing
  for (; endPos < str.length(); endPos ++) {
    char c = str[endPos];
    if (c == '(')
      stk += c;
    else if (c == ')')
      stk.remove(stk.length() - 1, 1);
    res += c;

    if (stk.length() == 0)
      break;
  }

  // remove outer pair of brackets
  res.remove(0, 1);
  res.remove(res.length() - 1, 1);

  return ++endPos;
}

double solve(String str) {

  double ans = 0;
  double nums[9];
  char ops[9];

  int nNums = 0;
  int nOps = 0;

  // parsing
  for (int i = 0; i < str.length(); ) {
    char c = str[i];
    if (nOps == nNums) {
      // get number
      if ((c >= '0' && c <= '9') || c == '-') {
        double num;
        i = getNum(str, i, num);
        nums[nNums++] = num;
      }
      // solve expression in brackets
      if (c == '(') {
        String bracket;
        i = getBracket(str, i, bracket);
        double num = solve(bracket);
        nums[nNums++] = num;
      }
    }
    
    // get operator
    if (c == '+' || c == '-' || c == 'X' || c == '/' || c == '^' || c == 'e') {
      i++;
      ops[nOps++] = c;
    }
  }

  // calculate
  while (nOps > 0) {
    int level = -1;
    int op = -1;
    for (int i = 0; i < nOps; i ++) {
      // get 
      if (level < 0 && (ops[i] == '+' || ops[i] == '-')) {
        level = 0;
        op = i;
      }
      if (level < 1 && (ops[i] == 'X' || ops[i] == '/')) {
        level = 1;
        op = i;
      }
      if (level < 2 && ops[i] == '^') {
        level = 2;
        op = i;
      }
      if (level < 3 && ops[i] == 'e') {
        level = 3;
        op = i;
      }
    }

    // calculate
    if (ops[op] == '+')
      nums[op] += nums[op + 1];
    if (ops[op] == '-')
      nums[op] -= nums[op + 1];
    if (ops[op] == 'X')
      nums[op] *= nums[op + 1];
    if (ops[op] == '/')
      nums[op] /= nums[op + 1];
    if (ops[op] == '^')
      nums[op] = pow(nums[op], nums[op + 1]);
    if (ops[op] == 'e')
      nums[op] *= pow(10, nums[op + 1]);

    // remove used number and operator
    for (int i = op; i < nOps - 1; i ++)
      ops[i] = ops[i + 1];
    for (int i = op + 1; i < nNums - 1; i ++)
      nums[i] = nums[i + 1];

    nOps--;
    nNums--;

  }

  return nums[0];
  
}

char idButton(int x, int y) {

  // check pointer position
  for (int i = 0; i < butRow; i ++) {
    for (int j = 0; j < butCol; j ++) {
      if (x >= j * boxHeight && x <= (j + 1) * boxHeight && 
          y >= extray + i * boxHeight && y <= extray + (i + 1) * boxHeight) {
        tft.drawRoundRect(row1x + j * boxWidth, extray + i * boxHeight, boxWidth, boxHeight, 8, ILI9341_RED);
        delay(100);
        tft.drawRoundRect(row1x + j * boxWidth, extray + i * boxHeight, boxWidth, boxHeight, 8, butColor[i][j]);
        return button[i][j];
      }
    }
  }
  
}
