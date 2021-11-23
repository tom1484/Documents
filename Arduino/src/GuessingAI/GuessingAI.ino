#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#define KEY_ROWS 4
#define KEY_COLS 4
#define OLED_RESET 4
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte colPins[KEY_COLS] = {9, 8, 7, 6};
byte rowPins[KEY_ROWS] = {13, 12, 11, 10};
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

char numbers[1250] = {0};
int a, b;
int gu;
int total;
int scroll = 0;
int u_gu;
int u_gt;
char u_mes[4];

Adafruit_SSD1306 display(OLED_RESET);

static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed((analogRead(0) % 23) * (analogRead(1) % 29));
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  numbers[1250] = {0};
  total = 5040;
  a = 0; b = 0;
  randomSeed(analogRead(0));
  for (int a = 1; a < 10000; a ++)
    if (isValid(a))
      bitWrite(numbers[a / 8], a % 8, 1);
}

void(* resetFunc) (void) = 0;

void loop() {
  gu = guess();
  int gt = gu;
  if (scroll % 2 == 0){
    display.clearDisplay();
  }
  display.setTextSize(1);
  display.setTextColor(WHITE);
  if (scroll == 0) display.setCursor(0, 0);
  else{
    if (scroll != 1){
      display.clearDisplay();
      printUp();
    }
    display.setCursor(0, 32);
    u_gu = gu;
    u_gt = gt;
  }
  scroll ++;
  display.print("Guess: ");
  while (gt < 1000){
    gt *= 10;
    display.print(0);
  }
  display.println(gu);
  display.println(' ');
  display.display();
  String mes = getMes();
  a = mes[0] - '0';
  b = mes[2] - '0';
  if (a == 4){
    display.setCursor(12, 24);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.print("I got it!");
    display.display();
    delay(2000);
    display.setCursor(12, 24);
    display.clearDisplay();
    display.print("New round");
    display.display();
    delay(1000);
    resetFunc();
  }
  delNum(gu, a * 10 + b);
  if (total < 1){
    display.setCursor(12, 24);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.print("  Wrong  ");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setCursor(12, 24);
    display.print(" Restart ");
    display.display();
    delay(1000);
    resetFunc();
  }
}

void printUp(){
  display.setCursor(0, 0);
  display.print("Guess: ");
  while (u_gt < 1000){
    u_gt *= 10;
    display.print(0);
  }
  display.println(u_gu);
  display.println(' ');
  for (int i = 0; i < 4; i ++){
    display.print(u_mes[i]);
  }

  display.display();
}

bool isValid(int n){
  int s[4] = {0};
  int k = 0;
  while (n < 1000){
    n *= 10;
  }
  while (n > 0){
    for (int i = 0; i < k; i ++) {
      if (s[i] == n % 10) return false;
    }
    s[k] = n % 10;
    k ++;
    n /= 10;
  }
  return true;
}

void delNum(int g, int ab){
  int m = millis();
  for (int i = 0; i < 10000; i ++){
    if (bitRead(numbers[i / 8], i % 8) == 0) continue;
    else{
      if (AB(g, i) != ab){
        bitWrite(numbers[i / 8], i % 8, 0);
        total --;
      }
    }
  }
  Serial.println(millis() - m);
}

int guess(){
  int g = random(0, 9999);
  while (bitRead(numbers[(g % 10000) / 8], (g % 10000) % 8) == 0){
    g ++;
  }
  return (g % 10000);
}

int AB(int n, int m){
  int a = 0, b = 0;
  int ar[4] = {getDigit(n, 0), getDigit(n, 1), getDigit(n, 2), getDigit(n, 3)};
  int br[4] = {getDigit(m, 0), getDigit(m, 1), getDigit(m, 2), getDigit(m, 3)};
  for (int i = 0; i < 4; i ++){
    for (int j = 0; j < 4; j ++){
      if (ar[i] == br[j])
      {
        b ++;
        if (i == j) a ++;
      }
    }
  }
  return a * 9 + b;
}

String tostr(int n){
  String str = "";
  while (n > 0){
    str = (char)('0' + n % 10) + str;
    n /= 10;
  }
  while (str.length() != 4){
    str = '0' + str;
  }
  return str;
}

int getDigit(int n, int d){
  for (int i = 0; i < d; i ++){
    n /= 10;
  }
  return n % 10;
}

String getMes(){
  String str = "";
  char key;
  while (str.length() < 4){
    key = myKeypad.getKey();
    delay(200);
    if (key){
      str += key;
      if (key == '#'){
        display.setCursor(12, 24);
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.clearDisplay();
        display.print(" Restart ");
        display.display();
        delay(1000);
        resetFunc();
      }
      u_mes[str.length() - 1] = key;
      if (str.length() == 4) display.println('B');
      else if (str.length() == 2) display.print('A');
      else display.print(key);
      display.display();
    }
  }
  return str;
}

