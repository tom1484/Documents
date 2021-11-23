#include <Keypad.h>

#define KEY_ROWS 4
#define KEY_COLS 4
 
char keymap[KEY_ROWS][KEY_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte colPins[KEY_COLS] = {6, 7, 8, 9};
byte rowPins[KEY_ROWS] = {2, 3, 4, 5};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
 
void setup(){
  Serial.begin(115200);
}

String str = "";
char copy;

void loop(){
  char key = myKeypad.getKey();
  if (key && key != '*' && key != '#'){
    str += key;
    copy = key;
    Serial.print(key);
  }
  else if (key == '*') {
    Serial.println("\nResult: " + str);
    str = "";
  }
  else if (key == '#') {
    Serial.println("\nDelete: " + String(copy));
    str.remove(str.length() - 1);
    Serial.print(str);
  }
}
