#include <Servo.h>

#define INSIDE 0
#define OUTSIDE 1
#define MID 75

class SpyderLeg {
public:
  Servo servo[2];
  void attach(int, int);
  void write(int, float);
  void origin(int);
private:
  float range[2] = {70, 70};
};

void SpyderLeg::attach(const int in, const int out) {
  servo[0].attach(in);
  servo[1].attach(out);
  origin(INSIDE);
  origin(OUTSIDE);
}

void SpyderLeg::write(const int target, float position) {
    servo[target].write(
      75 + map(position, -100, 100, -range[target] / 2, range[target] / 2)
    );
}

void SpyderLeg::origin(const int target) {
  write(target, 0);
}

SpyderLeg leg[4];

void setup() {
  // put your setup code here, to run once:
  leg[0].attach(2, 3);
  leg[1].attach(4, 5);
  leg[2].attach(6, 7);
  leg[3].attach(8, 9);
}
 
void loop() {
  leg[0].write(INSIDE,0);
  leg[0].write(OUTSIDE,0);
  leg[3].write(INSIDE,0);
  leg[3].write(OUTSIDE,0);
  leg[1].write(INSIDE,-100);
  leg[1].write(OUTSIDE,100);
  leg[2].write(INSIDE,100);
  leg[2].write(OUTSIDE,-100);
  delay(1000);
  leg[0].write(INSIDE,-100);
  leg[0].write(OUTSIDE,-100);
  leg[3].write(INSIDE,100);
  leg[3].write(OUTSIDE,100);
  leg[1].write(INSIDE,0);
  leg[1].write(OUTSIDE,0);
  leg[2].write(INSIDE,0);
  leg[2].write(OUTSIDE,0);
   delay(1000);
}
