#include "SpyderLeg.h"

void Leg::attach(int in, int out) {
  inside.attach(in);
  outside.attach(out);
  inside.write(90);
  outside.write(90);
}

void Leg::write(int target, int position) {
  position = project(position);
  if (target == 0)
    inside.write(position);
  else if (target == 1)
    outside.write(position);
}

int Leg::project(int position) {
  return map(position + 90, 0, 180, 0, 150);
}