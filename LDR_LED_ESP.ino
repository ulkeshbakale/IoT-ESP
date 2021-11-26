
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(A0);
float voltage = sensorValue * (5.0 / 1023.0);
Serial.println(voltage);
  if(voltage > 2.5)
  {
    digitalWrite(2,LOW);  
  }else
  {
    digitalWrite(2,HIGH);
  }
 delay(1000); 
}
