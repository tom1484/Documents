#include "Bluetooth.h"

void Bluetooth::attach(const int RX, const int TX) {
  BT = new SoftwareSerial(RX, TX);
  BT -> begin(9600);
}

bool Bluetooth::available() {
  return BT -> available();
}

//String Bluetooth::read() {
//  String str = "";
//
//  if (BT -> available()) {
//    while (BT -> available())
//      str += char(BT -> read());
//  } else {
//    str = "No Massage";
//  }
//
//  return str;
//}

char Bluetooth::read() {
  return BT -> read();
}
