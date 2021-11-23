int getDigit(int num, int index);
char answerSet[1250] = {0};

int getDigit(int number, int pos) {

}

bool isValid(int number) {


}
void setup()
{
  Serial.begin(9600);//每秒取樣9600次
  for (int i = 0; i < 1000; ++i)
    if (isValid(i)){
      bitWrite(answerSet[i/8], i%8, 1);
      }

  Serial.println(answerSet[14],BIN);
  Serial.println(answerSet[15],BIN);
  Serial.println(answerSet[16],BIN);
  
}


void loop()
{
}

