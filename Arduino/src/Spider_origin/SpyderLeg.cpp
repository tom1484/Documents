#include "SpyderLeg.h"

void SpyderLeg::attach(const int in, const int out) {
  inside.attach(in);
  outside.attach(out);
  write(INSIDE, 90);
  write(OUTSIDE, 50);
}

void SpyderLeg::write(const int target, float position) {
  if (target == 0)
    inside.write(position);
  else if (target == 1)
    outside.write(position);
}
