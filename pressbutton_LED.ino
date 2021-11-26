int led=13;
int pinButton=2;
int counter=0;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(pinButton,INPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int stateButton =digitalRead(pinButton);
  if (stateButton == 1){
  counter = counter+1;
  Serial.println("Button Pressed :" + String(counter) + "times" );
  if(counter % 2 == 1)
     {
  digitalWrite(led,HIGH);}
  else{
  digitalWrite(led,LOW);}
  }
   delay(500);
}
