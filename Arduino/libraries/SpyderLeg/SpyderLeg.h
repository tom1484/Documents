#ifndef SPYDERLEG_H
#define SPYDERLEG_H
#endif

#include <Arduino.h>
#include <Servo.h>

#define INSIDE 0
#define OUTSIDE 1

class Leg {
public:
  void attach(int, int);
  void write(int, int);
  int project(int);
private:
  Servo inside, outside;
};