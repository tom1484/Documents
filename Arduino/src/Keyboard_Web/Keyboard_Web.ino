#include <Keypad.h>
#include <SoftwareSerial.h>
SoftwareSerial myPort(10, 11);

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myPort.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

String keys = "";
String str = "";
char copy;

void loop() {
  // put your main code here, to run repeatedly:
  str = enter();
  char sendtext[str.length()];
  if (str.length() != 0) {
    str.toCharArray(sendtext, str.length()+1);
    myPort.write(sendtext);
    str = "";
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }
}

String enter() {
  keys = "";
  while (true) {
    char key = myKeypad.getKey();
    if (key && key != '*' && key != '#'){
      keys += key;
      copy = key;
      Serial.print(key);
    }
    else if (key == '*') {
      Serial.println("\nResult: " + keys);
      break;
    }
    else if (key == '#') {
      Serial.println("\nDelete: " + String(copy));
      keys.remove(keys.length() - 1);
      Serial.print(keys);
    }
  }
  return keys;
}

char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        return p;
    }
}

