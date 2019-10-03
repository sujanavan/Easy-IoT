#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YOUR WIFI NAME";  // YOUR WIFI NAME
const char* password = "YOUR WIFI PASSWORD";  // YOUR WIFI PASSWORD

int data=0;

void setup () {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting WiFi...");
    }
}
 
void loop() {
  String url="URL/data";  
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    data = http.getString().toInt();
    Serial.println(" Read = " + String(data));
    if(data==0)
    digitalWrite(LED_BUILTIN, LOW); 
    if(data==1)
    digitalWrite(LED_BUILTIN, HIGH);
    }
  http.end();
  delay(15000);         //Based on Cloud provider statistics
}
