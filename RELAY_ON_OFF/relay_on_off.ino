// === ESP32 1-Channel Relay Toggle Loop ===
// Relay turns ON and OFF repeatedly like an LED chaser.

#define RELAY_PIN 2   // GPIO pin connected to relay IN

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("ESP32 Relay Loop Started");
}

void loop() {
  // Turn relay ON
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("Relay ON");
  delay(1000);  // keep ON for 1 second

  // Turn relay OFF
  digitalWrite(RELAY_PIN, LOW);
  Serial.println("Relay OFF");
  delay(1000);  // keep OFF for 1 second
}
