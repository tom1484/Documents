#include <Keypad.h>
char anserSet[1250] = {0};
#include "LedControl.h"
LedControl lc=LedControl(12,10,11,1);//(din, clk, cs, #num)
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','b'},
    {'7','8','9','c'},
    {'*','0','#','d'}
// 每列的腳位編號
byte rowPins[ROWS] = {2, 3, 4, 5};
// 每行的腳位編號
byte colPins[COLS] = {6, 7, 8, 9};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char a = ' ';
char b = ' ';
boolean secondArguement = false;
char guess[4] = {'0','1','2','3'};

bool valid(int i){
  
  //***************************Write your valid(i) code below**********************************************
  
  bool valid =(i);
  
  return valid;
}

void restart(){
  for(int i = 0; i < 10000; i++){
    if(valid(i)){
      bitWrite(anserSet[i/8], i%8, 1);
    }
  }
  guessNext();
}

void deleteAns(){
  for (int i = 0; i < 10000; i++){
    if(bitRead(anserSet[i/8],i%8)){
      int a2 = 0;
      int b2 = 0;
      char Ans[4] = {i/1000+'0',(i%1000)/100+'0', (i%100)/10+'0', i%10+'0'};
      for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
          if(guess[j]==Ans[k]){
            if(j==k){
              a2+=1;
            }else{
              b2+=1;
            }
          }
        }
      }
      if(!(a2==(a-'0')&&b2==(b-'0'))){
        bitWrite(anserSet[i/8], i%8, 0);
      }
    }
  }
}

void guessNext(){
  int i = 0;
  int r = random(0122,9877);
  while((bitRead(anserSet[((i+r)%10000)/8],(i+r)%8)==0)&&i<10000){
    i++;
  }
  if(i==10000){
    lc.setChar(0,7,'E',false);
    lc.setChar(0,6,'A',false);
    lc.setChar(0,5,'A',false);
    lc.setChar(0,4,'0',false);
    tone(13,330,100);
    delay(200);
    tone(13,330,600);
    delay(1000);
    restart();
    return;
  }
  guess[0] = ((i+r)%10000)/1000+'0';
  guess[1] = ((i+r)%1000)/100+'0';
  guess[2] = ((i+r)%100)/10+'0';
  guess[3] = (i+r)%10+'0';
}

void Display(){
  lc.setChar(0,7,guess[0],false);
  lc.setChar(0,6,guess[1],false);
  lc.setChar(0,5,guess[2],false);
  lc.setChar(0,4,guess[3],false);
  lc.setChar(0,3,a,false);
  lc.setChar(0,2,'A',false);
  lc.setChar(0,1,b,false);
  lc.setChar(0,0,'b',false);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  randomSeed(analogRead(A0));
  restart();
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
  Display();
}
                                              
void loop() {
  char key = kpd.getKey();
  if(key>='0'&&key<='4'){
    if(secondArguement){
      b = key;
      tone(13,523,100);
      Display();
      //*******************************check if 4A0B emerges************************************  
      deleteAns();
      guessNext();
      secondArguement = false;
      delay(1000);
      a = ' ';
      b = ' ';
      Display();

    }
    else{
      a = key;
      Display();
      tone(13,523,100);
      secondArguement = true;
    }
  }else if(key=='A'){
    tone(13,523,100);
    a = ' ';
    b = ' ';
    secondArguement = false;
    restart();
    Display();
  }
}
