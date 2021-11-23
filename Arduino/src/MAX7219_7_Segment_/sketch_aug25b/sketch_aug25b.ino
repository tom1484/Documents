/* FILE:    HCMODU0082_Serial_7_Segment_Module_Example1
   DATE:    19/03/15
   VERSION: 0.2
   
REVISIONS:

12/03/15 Created version 0.1
19/03/15 Updated to work with V0.2 of the HCMAX7219 library

This is an example of how to use the Hobby Components serial 8 digit seven 7 
segment display module (HCMODU0082). To use this example sketch you will 
need to download and install the HCMAX7921 library available from the software
section of our support forum (forum.hobbycomponents.com) or on github:
(https://github.com/HobbyComponents)

The library assumes you are using one module. If you have more than one module
connected together then you will need to change the following line in the 
libraries HCMAX7219.h header file to the number of drivers you have connected:

#define NUMBEROFDRIVERS 1 <- Change this number


PINOUT:

MODULE.....UNO/NANO.....MEGA
VCC........+5V..........+5V
GND........GND..........GND
DIN........11...........51
CS (LOAD)..10...........10
CLK........13...........52

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of promoting products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, 
WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR
LACK OF NEGLIGENCE. HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE
FOR ANY DAMAGES INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR 
CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER. */

/* Include the HCMAX7219 and SPI library */
#include <HCMAX7219.h>
#include "SPI.h"

/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
 
/* Create an instance of the library */
HCMAX7219 HCMAX7219(LOAD);

void setup() 
{  
}

/* Main program */
void loop() 
{
  int h=0; 
  int m=0;
  int s=0;
  int i=0;
  int so=4;
  int mo=7;
  int ho=0;
  int io=1;
  int moo=7;
  int soo=4;
  int ioo=1;
  int p=1;
  for(;i<1001;i++)
  {
  if(i==10)
  io=ioo+p;
  if(i<10)
  io=ioo;
    /* Clear the output buffer */
  HCMAX7219.Clear();
  /* Write some text to the output buffer */
  HCMAX7219.print7Seg("00 00 00",8);
  if(i==100)
  {
    i=0;
    s++;
    if(s>9)
    so=soo+1;
    if(s<=9)
    so=soo;
  }
  if(s==60)
  {
    s=0;
    m++;
    if(m>9)
    mo=moo+1;
    if(m<=9)
    mo=moo;
  }
  if(m==60)
  {
    m=0;
    h++;
    ho=7;
    soo=1;
    moo=4;
    ioo=0;
    p=0;
    if(h==25)
    h=0;
    if(h>9)
    ho=8;
  }
  
  HCMAX7219.print7Seg(("%d", i),io);
  HCMAX7219.print7Seg(("%d", h),ho);
  HCMAX7219.print7Seg(("%d", s),so);
  HCMAX7219.print7Seg(("%d", m),mo);
  /* Send the output buffer to the display */
  HCMAX7219.Refresh();
  
  delay(10);
  /* Clear the output buffer */
  }
  
  while(1);

}
