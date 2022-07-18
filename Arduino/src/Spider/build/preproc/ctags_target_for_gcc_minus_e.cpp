# 1 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino"
# 2 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino" 2
# 3 "/home/tom1484/Documents/Arduino/src/Spider/Spider.ino" 2

SpyderLeg leg[4];

//Bluetooth BT;
Bluetooth BT;

int com;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  leg[0].attach(2, 3);
  leg[1].attach(4, 5);
  leg[2].attach(6, 7);
  leg[3].attach(8, 9);

  BT.attach(10, 11);

}

void loop() {
  com = BT.read();
leg[0].write(0,0);
   leg[0].write(1,0);
   leg[3].write(0,0);
   leg[3].write(1,0);
leg[1].write(0,-100);
   leg[1].write(1,100);
   leg[2].write(0,100);
   leg[2].write(1,-100);
   delay(1000);
   leg[0].write(0,-100);
   leg[0].write(1,-100);
   leg[3].write(0,100);
   leg[3].write(1,100);
   leg[1].write(0,0);
   leg[1].write(1,0);
   leg[2].write(0,0);
   leg[2].write(1,0);
   delay(1000);

  if (com == 1) {

  }
  else if (com == 2) {

  }
  else if (com == 3) {

  }
  else if (com == 4) {

  }
}
