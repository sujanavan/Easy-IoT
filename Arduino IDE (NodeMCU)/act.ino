// ACTUATOR only code for IDIOT: FREE & SIMPLE SaaS for IoT

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YOUR WIFI NAME";  // YOUR WIFI NAME
const char* password = "YOUR WIFI PASSWORD";  // YOUR WIFI PASSWORD

String email="YOUR EMAIL ID"; // YOUR EMAIL ID
String pass="YOUR ACCOUNT PASSWORD";  // YOUR ACCOUNT PASSSWORD

int status=0;

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
  String url="http://heart.atspace.tv/device_status.php?email="+email+"&pass="+pass;  
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    status = http.getString().toInt();
    Serial.println(" Read = " + String(status));
    if(status==1)                               // ACTUATOR STATUS = 1
    digitalWrite(LED_BUILTIN, LOW);             // For ESP LOW MEANS ON - ACTUATOR ACTION
    if(status==0)                               // ACTUATOR STATUS = 0
    digitalWrite(LED_BUILTIN, HIGH);            // For ESP HIGH MEANS OFF - ACTUATOR ACTION
    }
  http.end();
  delay(5000);
}
