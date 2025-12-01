#include <WiFi.h>

const char* ssid = "Giritharan R";
const char* password = "Password";

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  unsigned long startAttemptTime = millis();

  // Try for 20 seconds max
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 20000) {
    Serial.print(".");
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ Connection failed!");
    Serial.print("Status code: ");
    Serial.println(WiFi.status());
  }
}

void loop() {}