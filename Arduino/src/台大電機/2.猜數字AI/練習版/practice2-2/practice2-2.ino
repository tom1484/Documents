int getDigit(int number, int pos);

int getDigit(int number, int pos) {

}

bool isValid(int number) {


}
void setup()
{
  Serial.begin(9600);//每秒取樣9600次
  for (int i = 0; i < 1000; ++i)
    if (isValid(i)){
      Serial.println(i);
      }
}


void loop()
{
}

