#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YOUR WIFI NAME";  // YOUR WIFI NAME
const char* password = "YOUR WIFI PASSWORD";  // YOUR WIFI PASSWORD

void setup () {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting WiFi...");
    }
}
 
void loop() {
  float sensor = (analogRead(A0)/1024.0)*330;         // LM35 temperature sensor conversions
  //Check for change in temperature before upload to avoid redundant data
  String url="URL/sense.php?data="+String(sensor);  
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  http.end();
  delay(15000);
}
