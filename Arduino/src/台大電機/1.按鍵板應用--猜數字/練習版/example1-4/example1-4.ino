#include"LedControl.h"

LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
  lc.setChar(0, 7, 'H', false);
  lc.setChar(0, 6, 'E', false);
  lc.setChar(0, 5, 'L', false);
  lc.setChar(0, 4, 'L', false);
  lc.setChar(0, 3, '0', true);
}

void loop() {
  // put your main code here, to run repeatedly:
}
