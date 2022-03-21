#include <stdint.h>
#include <string.h>
#include <SoftwareSerial.h>
volatile uint8_t Checksum_Calc;
SoftwareSerial test(8,9);//RX,TX
void setup() {
  // put your setup code here, to run once:
  test.begin(500000);
  delay(2000);
}

void loop() {
   //put your main code here, to run repeatedly:
//UART_Send_SetMotorPosition(MotorID,Position,Speed);
    UART_Send_SetMotorPosition(1,2200,20);
  UART_Send_SetMotorPosition(2,800,1500);
    UART_Send_SetMotorPosition(1,2200,20);
  UART_Send_SetMotorPosition(2,800,1500);
    UART_Send_SetMotorPosition(1,2200,20);
  UART_Send_SetMotorPosition(2,800,1500);
  delay(1500);
  UART_Send_SetMotorPosition(1,800,20);
  UART_Send_SetMotorPosition(2,2200,1500);
    UART_Send_SetMotorPosition(1,800,20);
  UART_Send_SetMotorPosition(2,2200,1500);
    UART_Send_SetMotorPosition(1,800,20);
  UART_Send_SetMotorPosition(2,2200,1500);
  delay(1500);
     UART_Send_SetMotorPosition(1,0,0);
  UART_Send_SetMotorPosition(2,0,0); 
  
}

void UART_Send_SetMotorPosition(uint16_t motorId, uint16_t Postion, uint16_t Time)
{  
  Checksum_Calc = 0;
  UART_Send(0x80 + motorId);    //header mark & broadcast ID
  UART_Send(0x83);              //header mark & commaand code
  UART_Send(0x05);              //total data length
  UART_Send((Postion / 256) & 0x7F);  //Servo Pos_H
  UART_Send(Postion % 256);           //Servo Pos_L
  UART_Send((Time / 256) & 0x7F); //Servo Time_H
  UART_Send(Time % 256);          //Servo Time_L
  UART_Send(Checksum_Calc);       //data length (one servo with time and speed)
}

void UART_Send(uint8_t u8_byte_data)
{
  test.write(u8_byte_data);
  Checksum_Calc += u8_byte_data;
}

