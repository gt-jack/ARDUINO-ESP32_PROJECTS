int ldrPin = A0;     // LDR connected to analog pin A0
int relayPin = 7;    // Relay connected to digital pin 7
int ldrValue = 0;    // Variable to store LDR value
int threshold = 500; // Adjust threshold (0 - 1023)

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay off by default
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);   // Read LDR value
  Serial.println(ldrValue);        // Print to Serial Monitor

  if (ldrValue < threshold) {      // Dark condition
    digitalWrite(relayPin, LOW);   // Turn ON street light
  } else {
    digitalWrite(relayPin, HIGH);  // Turn OFF street light
  }

  delay(500);
}
