#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char getkey();
char king;
int r=0;
int intoch();
double multiplied(double, double);
double divided(double, double);
const int numRows = 4;
const int numCols = 4;
const int debounceTime = 50;

const char keymap[numRows][numCols]= {

  { '1','2','3','+' },

  {'4','5','6','-'  },

  {'7','8','9','*'  },

  {'=','0','#','/'  }
};
const int rowPins[numRows] = {13,10,9,8};
const int colPins[numCols] = {7,6,1,0};

void setup(){
Serial.begin(9600);
lcd.begin(16, 2);
for(int row = 0; row < numRows; row++){
   pinMode(rowPins[row],INPUT);
   digitalWrite(rowPins[row],HIGH);

}
for(int column = 0;column < numCols; column++){
    pinMode(colPins[column],OUTPUT);
    digitalWrite(colPins[column],HIGH);
 }
}

void loop() {
    lcd.clear();
    lcd.setCursor(0, 0);
    char key;
    king=0;
    r=0;
    double aa[15]={};
    int ll=0;
    aa[0]=0;
    aa[ll]=intoch();
    if(aa[ll] !=0){ 
    switch(king){
      case '*':aa[ll+1]=intoch();
               aa[ll+1]=multiplied(aa[ll], aa[ll+1]);
               break;
      case '/':aa[ll+1]=intoch();
               aa[ll+1]=divided(aa[ll], aa[ll+1]);
    }
    ll+=1;
    while(r!=1&&king!='#'){
    switch(king){
      case '*':aa[ll+1]=intoch();
               aa[ll+1]=multiplied(aa[ll], aa[ll+1]);
               break;
      case '/':aa[ll+1]=intoch();
               aa[ll+1]=divided(aa[ll], aa[ll+1]);
    }
    ll+=1;
    }
    if(r==1&&king!='#')
      Serial.println(aa[ll]);
      lcd.print(aa[ll]);
    }
    if(king=='#'){
      lcd.clear();
      lcd.setCursor(0, 0);
    }
  }

char getkey(){
    char key = 0;
    while(1){
    for(int column = 0;column < numCols; column++){
      digitalWrite(colPins[column],LOW);
      for(int row = 0 ;row < numRows; row++){
        if(digitalRead(rowPins[row]) == LOW){ 
          delay(debounceTime);
          while(digitalRead(rowPins[row]) == LOW)  
            ;
          key = keymap[row][column];   
        }
      }
      digitalWrite(colPins[column],HIGH); 
    }
    
    if(key!=0){
    break;  
    }
    }
    return key;
  }
  int intoch(){
    char p[15]={};
    int in[15]={};
    int t=0;
    int y=0;
    while(1){
        p[t]=getkey();
        lcd.print(p[t]);
        if(p[t]!='#')
        Serial.println(p[t]);
        else{
          Serial.print("RETURN\n");
        }
        if(p[t]=='+'||p[t]=='-'||p[t]=='*'||p[t]=='/'||p[t]=='#'){
            king=p[t];
            break;
        }
        if(p[t]=='='){
            r++;
            break;
        }
        t++;
    }
    int u=0;
    while(u<t){
        switch(p[u]){
    case '0':in[u]=0;
             break;
    case '1':in[u]=1;
             break;
    case '2':in[u]=2;
             break;
    case '3':in[u]=3;
             break;
    case '4':in[u]=4;
             break;
    case '5':in[u]=5;
             break;
    case '6':in[u]=6;
             break;
    case '7':in[u]=7;
             break;
    case '8':in[u]=8;
             break;
    case '9':in[u]=9;
    }
    y=0;
    while(y<t-1-u){
        in[u]=in[u]*10;
        y++;
    }
    u++;
    }
    u=0;
    int total=0;
    while(u<t){
        total+=in[u];
        u++;
    }
    return total;
}
double multiplied(double c, double d){
    return c*d;
}
double divided(double c, double d){
    return c/d;
}

