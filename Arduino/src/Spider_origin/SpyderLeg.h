#ifndef SPYDERLEG_H
#define SPYDERLEG_H
#endif

#include <Arduino.h>
#include <Servo.h>

#define INSIDE 0
#define OUTSIDE 1

class SpyderLeg {
public:
  Servo inside, outside;
  void attach(const int, const int);
  void write(const int, float);
};
