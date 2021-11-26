int LED = 2;
int IR = 16;
int buzzer = 4;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(IR);

  Serial.println(val);
  if (val > 0)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  if (val == 0)
  {
    count = count + 1;
    Serial.print("Object detected : Total count=");
    Serial.println(count);
    if (count > 10)
    {
      digitalWrite(buzzer, HIGH);
      tone(buzzer, 200, 3000);
    }
    else
    {
      digitalWrite(buzzer, LOW);
    }
  }

  else
  { count = count;
    Serial.print("object not detected :Total count =");
    Serial.println(count);
  }
 delay(1000);
}
