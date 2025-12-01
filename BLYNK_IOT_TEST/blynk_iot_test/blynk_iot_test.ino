/* Blynk IoT Home Automation (ESP32) */

#define BLYNK_TEMPLATE_ID "            "       // <-- Replace with your Template ID
#define BLYNK_TEMPLATE_NAME "home automation" // <-- Replace with your Template Name
#define BLYNK_AUTH_TOKEN "           " // Replace with your token

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Relay pins
#define relay1 23
//#define relay2 22

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "        ";   // your WiFi SSID
char pass[] = "        ";   // your WiFi password

BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  digitalWrite(relay1, value1 ? LOW : HIGH);
}

/*BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  digitalWrite(relay2, value2 ? LOW : HIGH);
}
*/
void setup() {
  Serial.begin(115200);

  pinMode(relay1, OUTPUT);
 // pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  //digitalWrite(relay2, HIGH);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  Serial.println("Connecting to Blynk...");
}

void loop() {
  Blynk.run();
}
