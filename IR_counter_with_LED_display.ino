#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
int IR =11;
int count;

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {3,2,8,7,6,4,5,9};
  bool resistorsOnSegments = true; 
  
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  pinMode(IR,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  int IRvalue = digitalRead(IR);
  Serial.println(IRvalue);
  if (IRvalue == 0)
  {
  count = count +1;
  
     sevseg.setNumber(count);
     sevseg.refreshDisplay(); // Must run repeatedly
  }  
  delay(1000);
}
