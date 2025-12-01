// Arduino code: DHT11 Temperature Monitor with Buzzer

#include "DHT.h"

#define DHTPIN 2          // DHT11 Data Pin connected to Arduino pin 2
#define DHTTYPE DHT11     // Define sensor type
#define BUZZER_PIN 8      // Buzzer connected to pin 8

DHT dht(DHTPIN, DHTTYPE);

const float tempThreshold = 30.0; // Temperature limit in Celsius

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature in Celsius

  if (isnan(temperature)) {
    Serial.println("Error reading temperature!");
    return;
  }

  Serial.println(temperature); // Send temp to Python

  if (temperature >= tempThreshold) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn ON buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Turn OFF buzzer
  }

  delay(2000); // Read every 2 seconds
}
