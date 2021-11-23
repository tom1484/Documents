#ifndef SPYDERLEG_H
#define SPYDERLEG_H
#endif

#include <Arduino.h>
#include <Servo.h>

#define INSIDE 0
#define OUTSIDE 1
#define MID 75

class SpyderLeg {
public:
  Servo servo[2];
  void attach(const int, const int);
  void write(const int, float);
  void origin(const int);
private:
  float range[2] = {70, 70};
};
