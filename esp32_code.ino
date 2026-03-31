#include <WiFi.h>
#include <HTTPClient.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""

#define FIREBASE_URL "https://real-time-soil-moisture-default-rtdb.asia-southeast1.firebasedatabase.app/soil/moisture.json"

#define SENSOR_PIN 34
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  int moisture = map(sensorValue, 0, 4095, 100, 0);

  Serial.println(moisture);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    http.begin(FIREBASE_URL);
    http.addHeader("Content-Type", "application/json");

    String data = String(moisture);

    int httpResponseCode = http.PUT(data);

    Serial.print("Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  if (moisture < 20) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);
}