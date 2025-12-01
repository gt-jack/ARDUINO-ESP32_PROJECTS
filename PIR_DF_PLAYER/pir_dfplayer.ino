#include <DFRobotDFPlayerMini.h>

#define PIR_PIN 13       // PIR sensor OUT to GPIO13
#define LED_PIN 14       // LED to GPIO14

DFRobotDFPlayerMini myDFPlayer;

bool motionPlayed = false;
unsigned long lastTriggerTime = 0;
const unsigned long delayAfterTrigger = 10000; // 10 seconds

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Start with LED off

  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // DFPlayer: RX=16, TX=17

  if (!myDFPlayer.begin(Serial2)) {
    Serial.println("DFPlayer not detected!");
    while (true);
  }

  Serial.println("DFPlayer Ready.");
  myDFPlayer.volume(25); // Volume: 0-30
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  unsigned long now = millis();

  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH); // 🔴 LED ON when motion detected

    if (!motionPlayed && (now - lastTriggerTime > delayAfterTrigger)) {
      Serial.println("Motion detected!");
      myDFPlayer.play(1);  // Play 0001.mp3
      motionPlayed = true;
      lastTriggerTime = now;
    }
  } else {
    digitalWrite(LED_PIN, LOW); // 🔵 LED OFF when no motion
    motionPlayed = false;       // Reset for next detection
  }
}
