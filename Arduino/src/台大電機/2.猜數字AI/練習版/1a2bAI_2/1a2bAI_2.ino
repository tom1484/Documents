#include <Keypad.h>

#include "LedControl.h"
LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)
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

char answerSet[1250] = {0};
char a = ' ';
char b = ' ';
bool secondArguement = false;
int guess = 1234;
int totalGuess = 5040;

int getDigit(int num, int index);
void guessNext();
void Display();

bool isValid(int number) {
}

int getDigit(int number, int pos) {
}

int getAB(int guess, int answer) {
}

void restart() {
    
  totalGuess = 5040;

  for (int i = 0; i < 10000; ++i)
    if (isValid(i)) 
       bitWrite(answerSet[i/8], i%8, 1);

  guessNext();
}

void deleteAns(int guess, int ab) {

  for (int i = 0; i < 10000; ++i) {
    if (bitRead(answerSet[i/8], i%8) == 0) continue;

    if (getAB(guess, i) != ab) {
       bitWrite(answerSet[i/8], i%8, 0);
      --totalGuess;
    }
  }

  if (totalGuess <= 0)  {
      Serial.println("error");
      lc.setChar(0,7,'E',false);
      lc.setChar(0,6,'A',false);
      lc.setChar(0,5,'A',false);
      lc.setChar(0,4,'0',false);
      tone(13,330,100);
      delay(200);
      tone(13,330,600);
      delay(1000);
      restart();
      Display();
  }
}

void guessNext() {
  int index = random() % totalGuess;
  int counter = 0;
  for (int i=0; i<10000; ++i) {
      if (bitRead(answerSet[i/8], i%8) != 0) 
          counter++;
      if (counter > index) {
          guess = i;
          break;
      }
  }

}

void Display() {
  lc.setChar(0,7,guess/1000,false);
  lc.setChar(0,6,guess/100%10,false);
  lc.setChar(0,5,guess/10%10,false);
  lc.setChar(0,4,guess%10,false);
  lc.setChar(0,3,a,false);
  lc.setChar(0,2,'A',false);
  lc.setChar(0,1,b,false);
  lc.setChar(0,0,'b',false);
}

void setup()
{
  Serial.begin(9600);//每秒取樣9600次
  pinMode(13,OUTPUT);
  randomSeed(analogRead(A0));
  restart();
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
  Display();
}

void loop()
{
  char key = kpd.getKey();

  if (key >= '0' && key <= '4') {
    if (secondArguement) {
      b = key;
      tone(13,523,100);
      Display();
      deleteAns(guess,  ((a-'0')*10+(b -'0')));
      guessNext();
      secondArguement = false;
      a = ' ';
      b = ' ';
      Display();
    }
    else {
      a = key;
      tone(13,523,100);
      Display();
      secondArguement = true;
    }
  }
  else if (key == 'A') {
    restart();
    Display();
  }
}

