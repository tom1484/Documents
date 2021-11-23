#include "Arduino.h"
#include <Keypad.h>
#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); //(din, clk, cs, #num)

void printDetail(uint8_t type, int value);

int NOTE[64] = { 0,  0,  0,  0,  0,  0, 31,
                 33, 37, 41, 44, 49, 55, 62,
                 65, 73, 82, 87, 98, 110, 123,
                 131, 147, 165, 175, 196, 220, 247,
                 262, 294, 330, 349, 392, 440, 493,
                 523, 587, 659, 698, 784, 880, 988,
                 1047, 1175, 1319, 1397, 1568, 1760, 1976,
                 2093, 2349, 2637, 2794, 3136, 3520, 3951,
                 4186, 4699, 5274, 5588, 6272, 7040, 7902,
               };
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'b'},
  {'7', '8', '9', 'c'},
  {'*', '0', '#', 'd'}
};
char S[4] = {'S', 't', 'A', 'r'};//左半邊顯示器內容
char CHK[4] = {'t', ' ', ' ', ' '};//右半邊顯示器內容
char R[4] = {0, 0, 0, 0};//正確答案
char keypressed;
byte rowPins[ROWS] = {2, 3, 4, 5};//connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9};//connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int i = 0, tries = 0, octave = 4;
boolean waitforRestart = false, inputnorepeat = true, showanswer = false, pianomode = false;

#define speakerpin 13

void switch2piano() {
  tone(speakerpin, 262);
  delay(300);
  tone(speakerpin, 330);
  delay(300);
  tone(speakerpin, 392);
  delay(300);
  tone(speakerpin, 523);
  delay(300);
  noTone(speakerpin);
}

void switch2game() {
  tone(speakerpin, 523);
  delay(300);
  tone(speakerpin, 392);
  delay(300);
  tone(speakerpin, 330);
  delay(300);
  tone(speakerpin, 262);
  delay(300);
  noTone(speakerpin);
}

void keypadEvent(KeypadEvent key)
{
  inputnorepeat = true;
  switch (keypad.getState())
  {
    case PRESSED:
      if (pianomode)
      {
        if ((key >= '0') && (key <= '9'))
        {
          tone(speakerpin, NOTE[key - '0' + octave * 7 - 1]);
          lc.setChar(0, 7, 127, false);
          lc.setChar(0, 6 - (key % 7), 'd', false);
        }
        else if (key == '#')
        {
          octave++;
          if (octave > 7) octave = 7;
        }
        else if (key == '*')
        {
          octave--;
          if (octave < 2) octave = 2;
        }
        else if (key == 'A')
        {
          pianomode = false;
          switch2game();
          restart();
        }
      }
      else
      {
        if ((key >= '0') && (key <= '9') && (!waitforRestart))
        {
          tone(speakerpin, NOTE[key - '0' + 27]);
          delay(50);
          noTone(speakerpin);
          for (int j = 0; j < i; j++)
          {
            if (key == S[j])
            {
              inputnorepeat = false;
            }
          }
          if (i == 0)
          {
            S[1] = '-';
            S[2] = '-';
            S[3] = '-';
          }
          if (inputnorepeat)
          {
            S[i] = key;
            i++;
          }
          showDigits();

          if (i == 4)
          { i = 0;
            checkAnswer();
          }
        }
        else if (key == 'A')
        {
          i = 0;
          restart();
        }
        else if (key == 'b')
        {
          pianomode = true;
          octave = 4;
          lc.clearDisplay(0);
          lc.setChar(0, 7, 127, false);
          switch2piano();
        }
        else if (key == '*')
        {
          showanswer = !showanswer;
          showDigits();
        };
      };
      break;
    case RELEASED:
      noTone(speakerpin);
      lc.setChar(0, 6 - (key % 7), ' ', false);
      break;
    case HOLD:
      break;
  }
}

void showDigits(void)
{
  if (!pianomode)
  {
    lc.setChar(0, 7, S[0], false);
    lc.setChar(0, 6, S[1], false);
    lc.setChar(0, 5, S[2], false);
    lc.setChar(0, 4, S[3], false);
    if (showanswer)
    {
      lc.setChar(0, 3, R[0] + 48, false);
      lc.setChar(0, 2, R[1] + 48, false);
      lc.setChar(0, 1, R[2] + 48, false);
      lc.setChar(0, 0, R[3] + 48, false);
    } else
    {
      lc.setChar(0, 3, CHK[0], false);
      lc.setChar(0, 2, CHK[1], false);
      lc.setChar(0, 1, CHK[2], false);
      lc.setChar(0, 0, CHK[3], false);
    }
  }
}

void restart(void)
{
  waitforRestart = false;
  tries = 0;
  S[0] = 'S';
  S[1] = 't';
  S[2] = 'A';
  S[3] = 'r';
  CHK[0] = 't';
  CHK[1] = ' ';
  CHK[2] = ' ';
  CHK[3] = ' ';
  showanswer = false;
  showDigits();
  generate();
  S[0] = '-';
  S[1] = '-';
  S[2] = '-';
  S[3] = '-';
  CHK[0] = ' ';
  CHK[1] = ' ';
  CHK[2] = ' ';
  CHK[3] = ' ';
  showDigits();
  //play(14); //Game Start
}

void clearstage() {
  int ryth[52] = {23, 25, 27, 27, 28, 28, 28, 30, 33, 33, 33, 0, 31, 31, 31, 0, 28, 30, 31, 31, 32, 32, 32, 33, 34, 34, 34, 0, 32, 32, 32, 0, 29, 30, 31, 31, 32, 32, 32, 33, 34, 34, 0, 0, 34, 34, 0, 34, 35, 35, 35, 35};
  for (int i = 0; i < 52; i++) {
    if (ryth[i]) {
      tone(speakerpin, NOTE[ryth[i]]);
    } else {
      noTone(speakerpin);
    }
    delay(120);
  }
  noTone(speakerpin);
}

void checkAnswer(void)
{
  int a = 0;
  int b = 0;
  tries++;  
  //----------------在這裡檢查輸入與正確解答有多少吻合，並將幾A幾B的結果寫入CHK[]之中(右半邊顯示器內容)-----------------------------------------------------------------------------------
  
  if (a == 0)
  {
    switch (b)
    {
      case 0:
        CHK[0] = '0';
        CHK[1] = 'A';
        CHK[2] = '0';
        CHK[3] = 'b';
        showDigits();
        break;
      case 1:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '1';
        CHK[3] = 'b';
        showDigits();
        break;
      case 2:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '2';
        CHK[3] = 'b';
        showDigits();
        break;
      case 3:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '3';
        CHK[3] = 'b';
        showDigits();
        break;
      case 4:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '4';
        CHK[3] = 'b';
        showDigits();
        break;
      default:
        break;
    }
  }
  if (a == 1)
  {
    switch (b)
    {
      case 0:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '1';
        CHK[3] = 'A';
        showDigits();
        break;
      case 1:
        CHK[0] = '1';
        CHK[1] = 'A';
        CHK[2] = '1';
        CHK[3] = 'b';
        showDigits();
        break;
      case 2:
        CHK[0] = '1';
        CHK[1] = 'A';
        CHK[2] = '2';
        CHK[3] = 'b';
        showDigits();
        break;
      case 3:
        CHK[0] = '1';
        CHK[1] = 'A';
        CHK[2] = '3';
        CHK[3] = 'b';
        showDigits();
        break;
      case 4:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '4';
        CHK[3] = 'b';
        showDigits();
        break;
      default:
        break;
    }
  }
  if (a == 2)
  {
    switch (b)
    {
      case 0:
        CHK[0] = ' ';
        CHK[1] = ' ';
        CHK[2] = '2';
        CHK[3] = 'A';
        showDigits();
        break;
      case 1:
        CHK[0] = '2';
        CHK[1] = 'A';
        CHK[2] = '1';
        CHK[3] = 'b';
        showDigits();
        break;
      case 2:
        CHK[0] = '2';
        CHK[1] = 'A';
        CHK[2] = '2';
        CHK[3] = 'b';
        showDigits();
        break;
      default:
        break;
    }
  }
  if (a == 3)
  {
    CHK[0] = ' ';
    CHK[1] = ' ';
    CHK[2] = '3';
    CHK[3] = 'A';
    showDigits();
  }
  if (a == 4)
  {
    CHK[0] = ' ';
    CHK[1] = ' ';
    CHK[2] = '4';
    CHK[3] = 'A';
    showDigits();
    clearstage();
    waitforRestart = true;
  };
}


void generate(void)
{
  int i = 0;
  int r;
  boolean alreadyexist;
  randomSeed(millis());
  while (i < 4)
  {
    alreadyexist = false;
    r = random(0, 10);
    for (int j = 0; j < i; j++)
    {
      if (r == R[j])
      {
        alreadyexist = true;
      }
    }
    if (!alreadyexist)
    {
      R[i] = r;
      i++;
    }
  }
}

void setup()
{
  lc.shutdown(0, false);
  /* clear the display */
  lc.setIntensity(0, 5);
  /* Set the brightness to a medium values */
  lc.clearDisplay(0);
  Serial.begin(9600);
  keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
  keypad.setHoldTime(5);
  keypad.setDebounceTime(1);
  pinMode(speakerpin, OUTPUT);
  showDigits();
  randomSeed(analogRead(A0));
  restart();
}

void loop()
{
  char key = keypad.getKey();
  showDigits();
}

