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

#define ledpin1 A1
#define ledpin2 A2
int num = 0;
int long1 = 0;
int short1 = 0;
int long2 = 0;

void Display(int a){
  lc.setChar(0,0,a,false);
}
void longSymbol()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delayMicroseconds(3000);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delayMicroseconds(1000);
}

void shortSymbol()
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delayMicroseconds(1000);
}

void setup()
{
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
}

void loop()
{

  char key = kpd.getKey();
  if (key) // Check for a valid key.
  {
    Display(key-'0');
    switch (key)
    {
      default:
        num = key - '0';
        if (num > 5) {
          long1 = 0;
          long2 = num - 5;
          short1 = 10 - num;
        } else {
          long1 = 5 - num;
          long2 = 0;
          short1 = num;
        }
    }
  }
  for (int i = 0; i < long1; i++) {
    longSymbol();
  }
  for (int i = 0; i < short1; i++) {
    shortSymbol();
  }
  for (int i = 0; i < long2; i++) {
    longSymbol();
  }
  delayMicroseconds(400);
}
