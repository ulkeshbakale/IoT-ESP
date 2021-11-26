/* SevSeg Counter Example
 
 Copyright 2020 Dean Reading
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {3,2,8,7,6,4,5,9};
  bool resistorsOnSegments = true; 
  
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() 
{
  for(int i=0; i<10;i++)
  {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); // Must run repeatedly
     delay(2000);
  }  
}

/// END ///
