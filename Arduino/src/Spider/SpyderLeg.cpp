#include "SpyderLeg.h"

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
