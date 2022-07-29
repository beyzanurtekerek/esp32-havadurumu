#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const String url = "http://api.weatherapi.com/v1/current.json?key=66d31c216a7d49e8abb151525222205&q=HATAY&aqi=no";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");


  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }

 HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  String data = "{}";
  data = http.getString();
  http.end();
  
  JSONVar havaJson = JSON.parse(data);

  Serial.println();
  Serial.println("-----------------HAVA DURUMU------------------");
  Serial.print("Hava sicakligi: ");
  Serial.print(havaJson["current"]["temp_c"]);
  Serial.println(" derece");
  Serial.print("Hissedilen sicaklik: ");
  Serial.print(havaJson["current"]["feelslike_c"]);
  Serial.println(" derece");
}
void loop() {
  delay(100);
}
