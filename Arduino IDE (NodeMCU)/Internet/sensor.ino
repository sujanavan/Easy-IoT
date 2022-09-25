#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

String URL="<<<HTTP-URL-ONLY-HTTP>>>/write.php?data=";
int temp=0;

void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("<<<WIFI-NAME>>>", "<<<WIFI-PASSWORD>>>");
}

void loop() {

  /* 
  LM-35 SENSOR INITIALIZATION TO BE ADDED IN SETUP
  THEN HERE GET SENSOR VALUE
  CONVERT THE VALUE into temp variable  
  */  
  
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;
    
    Serial.println(URL+temp);

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, URL+temp)) {  // HTTP URL added to temp


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          Serial.printf("[HTTP] Data Sent to Server Successfully\n");
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  }

  delay(2000);
}
