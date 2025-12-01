#define SOUND_SENSOR_PIN 4
#define LED_PIN 2   // Optional: onboard LED (or external one)

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Sound sensor test started...");
}

void loop() {
  int soundValue = digitalRead(SOUND_SENSOR_PIN);

  if (soundValue == HIGH) {
    Serial.println("Sound detected!");
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50); // Small delay for stability
}
