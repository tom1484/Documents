#include <Servo.h>
#include <SoftwareSerial.h>

class Tier {
  public:
    int p1, p2;
    
    Tier(int _p1, int _p2, bool reverse) {
      if (reverse) {
        p1 = _p2;
        p2 = _p1;
      } else {
        p1 = _p1;
        p2 = _p2;
      }

      pinMode(p1, OUTPUT);
      pinMode(p2, OUTPUT);
    }

    void forward() {
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
    }

    void back() {
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
    }

    void stop() {
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
    }
};

Tier left(3, 4, true);
Tier right(5, 6, false);

SoftwareSerial BT(8, 9);

void setup() {
  // put your setup code here, to run once:
  left.forward();
  right.forward();
  left.stop();
  right.stop();

  BT.begin(38400);
  Serial.begin(38400);  
}

void loop() {
  // put your main code here, to run repeatedly:
  char val;

  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
  }
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(char(val));

    if (val == 'l') {
      left.back();
      right.forward();
      delay(50);
      left.stop();
      right.stop();
    }

    if (val == 'r') {
      left.forward();
      right.back();
      delay(50);
      left.stop();
      right.stop();
    }

    if (val == 'u') {
      left.forward();
      right.forward();
    }

    if (val == 'b') {
      left.back();
      right.back();
    }

    if (val == 's') {
      left.stop();
      right.stop();
    }
  }
}
