#include <stdint.h>
#include <string.h>
#include <SoftwareSerial.h>
volatile uint8_t Checksum_Calc;
int a=0;
SoftwareSerial test(8,9);//RX,TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(500000);
  test.begin(500000);
  delay(2000);
}

void loop() {
   //put your main code here, to run repeatedly:
  a=Serial.parseInt();
  if(!a){
    }else{
  UART_Send_SetID(a);
  Serial.print("ID to:");
  Serial.println(a);
    }
}

void UART_Send_SetID(uint16_t motorID)
{  
  Checksum_Calc = 0;
  UART_Send(0x80);    //header mark & broadcast ID
  UART_Send(0x92);              //header mark & commaand code
  UART_Send(0x20);              //total data length
  UART_Send(0x00);  //Servo Pos_H
  UART_Send(motorID);           //Servo ID
  UART_Send(Checksum_Calc);       //data length (one servo with time and speed)
}

void UART_Send(uint8_t u8_byte_data)
{
  test.write(u8_byte_data);
  Checksum_Calc += u8_byte_data;
}

