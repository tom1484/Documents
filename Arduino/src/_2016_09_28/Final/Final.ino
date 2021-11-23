
//=====================================================================================================================================================

#include "I2Cdev.h"

#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"

#endif

MPU6050 mpu;

#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 2 

#define LED_PIN 13 

bool blinkState = false;

bool dmpReady = false; 

uint8_t mpuIntStatus;

uint8_t devStatus;   

uint16_t packetSize;

uint16_t fifoCount;   

uint8_t fifoBuffer[64]; 

Quaternion q;        

VectorInt16 aa;        

VectorInt16 aaReal;    

VectorInt16 aaWorld;   

VectorFloat gravity;  

float euler[3];         

float ypr[3];           

uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };

volatile bool mpuInterrupt = false;    

void dmpDataReady() {
    mpuInterrupt = true;
}

//=====================================================================================================================================================

float voltage = 0;

void setup() {
  
  MPU_Setup();

  pinMode(7, OUTPUT);
  
  pinMode(A3, INPUT);

  digitalWrite(7, LOW);
  
}

void loop() {

  MPU_Run();

  volt_alarm();

  
}
