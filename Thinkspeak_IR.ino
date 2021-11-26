
#include <ESP8266WiFi.h>
int val;
int IR = 4;
int count;

String apiKey = "OIIVL6JUBQTM784I";

const char *ssid =  "iPhone";
const char *pass =  "ulkesh@007";
const char* server = "api.thingspeak.com";


WiFiClient client;

void setup()
{
  pinMode(IR, INPUT);
  Serial.begin(115200);
  delay(10);


  Serial.println("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop()
{
  val = digitalRead(IR);
  Serial.println(val);
  if (val == 0)
   {
    count=count+1;
    Serial.print("Count: ");
    Serial.println(count);
    
   }
   
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {

      String postStr = apiKey;
      postStr += "&field3=";
      postStr += String(count);

      postStr += "\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Object detected: ");
      Serial.print(count);
      Serial.println(" Send to Thingspeak.");
    }
  client.stop();

  Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(1000);
}
