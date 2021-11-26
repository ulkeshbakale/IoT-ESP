int PIR = 4;
int LED = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(PIR);
  Serial.println(val);
  if (val == HIGH)
  {
    digitalWrite(LED, LOW);
    Serial.println("MOTION DETECTED !!");
  } else
  {
    digitalWrite(LED, HIGH);
    Serial.println("MOTION NOT DETECTED !!");
  }
  delay(1000);
}
