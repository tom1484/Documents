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
  byte Loopcounter;
  byte Position;
   
  /* SCROLL SOME TEXT 5 TIMES BEFORE MOVING ON */
  for (Loopcounter = 0; Loopcounter <= 5; Loopcounter++)
  {
    /* We are scrolling 30 characters of text across the entire display */
    for (Position = 0; Position <= DISPLAYBUFFERSIZE + 30; Position++)
    { 
      /* Write the test to the output buffer at the position we require */
      HCMAX7219.print7Seg("HCMAX7219 SCROLLING TEXT DEMO ",Position);
      /* Send the output buffer to the display */
      HCMAX7219.Refresh();  
      delay(200);
    }
  }
   
   
  /* WE CAN ALSO DISPLAY INTEGER NUMBERS */
   
  /* Clear the output buffer */
  HCMAX7219.Clear();
  /* Write some text and output it*/
  HCMAX7219.print7Seg("INT NUM.",8);
  HCMAX7219.Refresh();
  delay(2000);
   
  /* display an example of a negative integer number */
  HCMAX7219.Clear();
  HCMAX7219.print7Seg(-1234567,8);
  HCMAX7219.Refresh();
  delay(2000);
   
  /* Clear the output buffer */
  HCMAX7219.Clear();
  /* Write some text and output it*/
  HCMAX7219.print7Seg("WITH DP.",8);
  HCMAX7219.Refresh();
  delay(2000);
   
  /* Show the DP in different places. Notice when the DP is at the 
    beginning the number is padded with a zero */
  HCMAX7219.Clear();
  for (Position = 1; Position <= 7; Position++)
  { 
    HCMAX7219.print7Seg(-1234567,Position,8);
    HCMAX7219.Refresh();
    delay(1000);
  }
}
