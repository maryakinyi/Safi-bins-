#include <ESP8266WiFi.h> 
const char* SSID ="Codehive";
const char* password ="codehive!" ;
int distance;
long duration;
const int trig=2;
const int echo=3;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.print(SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(echo, INPUT); 
  pinMode(trig, OUTPUT);
}

void loop() {
   digitalWrite(trig, LOW);
   delayMicroseconds(3);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);

    duration =pulseIn(echo, HIGH);
    distance = duration*0.034 /2;
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.print(" CM");
    Serial.println("");  
   delay(1000);
}
