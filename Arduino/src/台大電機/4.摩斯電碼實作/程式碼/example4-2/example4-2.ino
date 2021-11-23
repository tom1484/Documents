#include <Keypad.h>
#include "LedControl.h"
LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
// 每列的腳位編號
byte rowPins[ROWS] = {2, 3, 4, 5};
// 每行的腳位編號
byte colPins[COLS] = {6, 7, 8, 9};

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define speakerpin 13
#define ledpin1 A1
#define ledpin2 A2

void longSymbol()
{
  tone(speakerpin, 440);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(300);
  noTone(speakerpin);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(100);
}

void shortSymbol()
{
  tone(speakerpin, 440);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(100);
  noTone(speakerpin);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(100);
}

void setup()
{
  pinMode(speakerpin, OUTPUT);
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
}

void Display(int a){
  lc.setChar(0,0,a,false);
}


void loop()
{
  char key = kpd.getKey();
  if (key) // Check for a valid key.
  {
    Display(key-'0');
    switch (key)
    {
      case '1':
        shortSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        delay(200);
        break;
      case '2':
        shortSymbol();
        shortSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        delay(200);
        break;
      case '3':
        shortSymbol();
        shortSymbol();
        shortSymbol();
        longSymbol();
        longSymbol();
        delay(200);
        break;
      case '4':
        shortSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        longSymbol();
        delay(200);
        break;
      case '5':
        shortSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        delay(200);
        break;
      case '6':
        longSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        delay(200);
        break;
      case '7':
        longSymbol();
        longSymbol();
        shortSymbol();
        shortSymbol();
        shortSymbol();
        delay(200);
        break;
      case '8':
        longSymbol();
        longSymbol();
        longSymbol();
        shortSymbol();
        shortSymbol();
        delay(200);
        break;
      case '9':
        longSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        shortSymbol();
        delay(200);
        break;
      case '0':
        longSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        longSymbol();
        delay(200);
        break;
    }
      lc.clearDisplay(0);
  }
}
