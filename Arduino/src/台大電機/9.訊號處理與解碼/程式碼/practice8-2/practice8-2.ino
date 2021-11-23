#include "Arduino.h"
#include <Keypad.h>
#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); //(din, clk, cs, #num)

int i = 0;
String bits = "";
String bitsRLL = "1100111001";
int v = 0;
String s = "";
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'b'},
  {'7', '8', '9', 'c'},
  {'*', '0', '#', 'd'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  lc.shutdown(0, false);
  /* clear the display */
  lc.setIntensity(0, 5);
  /* Set the brightness to a medium values */
  lc.clearDisplay(0);
  keypad.addEventListener(kpdEvent);
  keypad.setDebounceTime(1);
  keypad.setHoldTime(5);
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void kpdEvent(KeypadEvent key) {
  if (keypad.getState() == PRESSED) {
    if ((key >= '0') && (key <= '9') && (i <= 2)) {
      lc.setChar(0, 7 - i, key, false);
      i++;
      s += key;
    } else if (key == 'A') {
      for (int j = 0; j < i; j++) {
        v += s[j] - '0';
        v = v * 10;
      }
      v = v/10;
      if (v > 255) {
        lc.setChar(0, 7, 'E', false);
        lc.setChar(0, 6, 'A', false);
        lc.setChar(0, 5, 'A', false);
        lc.setChar(0, 4, '0', false);
        delay(1000);
      } else {
        for (int j = 0; j < 8; j++) {
          if (v % 2) {
            bits += '1';
          } else {
            bits += '0';
          }
          v = v / 2;
        }
        Serial.println(bits);
        RLL(bits);
        Serial.println(bitsRLL);
      }
      lc.clearDisplay(0);
      bits = "";
      i = 0;
      v = 0;
      s = "";
    }
  }
}

void on() {
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  delayMicroseconds(222);
}

void off() {
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  delayMicroseconds(222);
}

void transmit() {
  on();
  off();
  on();
  off();
  on();
  off();
  off();
  off();
  for (int k = 0; k < 10; k++) {
    if (bitsRLL[k] == '0') {
      off();
    } else {
      on();
    }
  }
}

void RLL(String b) {
  bitsRLL = "";
  if (b.substring(0,4) == "0000") {
    bitsRLL += "11001";
  } else if (b.substring(0,4) == "0001") {
    bitsRLL += "11011";
  } else if (b.substring(0,4) == "0010") {
    bitsRLL += "10010";
  } else if (b.substring(0,4) == "0011") {
    bitsRLL += "10011";
  } else if (b.substring(0,4) == "0100") {
    bitsRLL += "11101";
  } else if (b.substring(0,4) == "0101") {
    bitsRLL += "10101";
  } else if (b.substring(0,4) == "0110") {
    bitsRLL += "10110";
  } else if (b.substring(0,4) == "0111") {
    bitsRLL += "10111";
  } else if (b.substring(0,4) == "1000") {
    bitsRLL += "11010";
  } else if (b.substring(0,4) == "1001") {
    bitsRLL += "01001";
  } else if (b.substring(0,4) == "1010") {
    bitsRLL += "01010";
  } else if (b.substring(0,4) == "1011") {
    bitsRLL += "01011";
  } else if (b.substring(0,4) == "1100") {
    bitsRLL += "11110";
  } else if (b.substring(0,4) == "1101") {
    bitsRLL += "01101";
  } else if (b.substring(0,4) == "1110") {
    bitsRLL += "01110";
  } else if (b.substring(0,4) == "1111") {
    bitsRLL += "01111";
  }
  if (b.substring(4) == "0000") {
    bitsRLL += "11001";
  } else if (b.substring(4) == "0001") {
    bitsRLL += "11011";
  } else if (b.substring(4) == "0010") {
    bitsRLL += "10010";
  } else if (b.substring(4) == "0011") {
    bitsRLL += "10011";
  } else if (b.substring(4) == "0100") {
    bitsRLL += "11101";
  } else if (b.substring(4) == "0101") {
    bitsRLL += "10101";
  } else if (b.substring(4) == "0110") {
    bitsRLL += "10110";
  } else if (b.substring(4) == "0111") {
    bitsRLL += "10111";
  } else if (b.substring(4) == "1000") {
    bitsRLL += "11010";
  } else if (b.substring(4) == "1001") {
    bitsRLL += "01001";
  } else if (b.substring(4) == "1010") {
    bitsRLL += "01010";
  } else if (b.substring(4) == "1011") {
    bitsRLL += "01011";
  } else if (b.substring(4) == "1100") {
    bitsRLL += "11110";
  } else if (b.substring(4) == "1101") {
    bitsRLL += "01101";
  } else if (b.substring(4) == "1110") {
    bitsRLL += "01110";
  } else if (b.substring(4) == "1111") {
    bitsRLL += "01111";
  }
}

void loop()
{
  char key = keypad.getKey();
  transmit();
}
