int getDigit(int number, int pos) {




}

void setup()
{
  Serial.begin(9600);//每秒取樣9600次
  Serial.print("1234,1=");
  Serial.println(getDigit(1234,1));
  Serial.print("0123,0=");
  Serial.println(getDigit(0123,0));
  Serial.print("2345,1=");
  Serial.println(getDigit(2345,1));
  Serial.print("4782,3=");
  Serial.println(getDigit(4782,3));
  Serial.print("6012,1=");
  Serial.println(getDigit(6012,1));
  Serial.print("1832,2=");
  Serial.println(getDigit(1832,2));
}


void loop()
{

}

