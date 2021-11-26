#include <MD_MAX72xx.h>
#include <SPI.h>

#include <LedControl.h>

#include <LedControlMS.h>

#include <MD_MAX72xx.h>
#include <SPI.h>

#include <LedControl.h>

#include "LedControlMS.h"
int val;
int tempPin = A0;
int LED;
float mv;
 
 //pin 12 is connected to the DataIn
// pin 11 is connected to the CLK
 //pin 10 is connected to LOAD
 
#define NBR_MTX 1 //number of matrices attached is one
LedControl lc=LedControl(12,11, 10, NBR_MTX);//
 
void setup()
{
  for (int i=0; i< NBR_MTX; i++)
  {
    lc.shutdown(i,false);
  /* Set the brightness to a medium values */
    lc.setIntensity(i,8);
  /* and clear the display */
    lc.clearDisplay(i);
                delay(500);
  }
}
 
void loop()
 
{
  float temp=30.650;
  val = analogRead(tempPin);

float mv = (val/1024.0)*5000;
float cel = mv/10;
Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
delay(1000);
if(cel>31.5)
{
  digitalWrite(LED,HIGH);
}
else
{
  digitalWrite(LED,LOW);
}
Serial.println();

delay(1000);
     lc.writeString(0,String(temp));//sending characters to display
     lc.clearAll();//clearing the display
     delay(1000);
}
