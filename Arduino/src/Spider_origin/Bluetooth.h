#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#endif

#include <Arduino.h>
#include <SoftwareSerial.h>

//#define RX 8
//#define TX 9

class Bluetooth {
public:
  void attach(const int, const int);
  bool available();
//  String read();
  char read();
private:
  SoftwareSerial* BT;
};
