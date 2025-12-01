const int reedPin = 2;      // Reed switch to D2
const int lightPin = 13;    // LED or light on D13

void setup() {
  pinMode(reedPin, INPUT_PULLUP); // Internal pull-up
  pinMode(lightPin, OUTPUT);
}

void loop() {
  int reedState = digitalRead(reedPin);

  if (reedState == HIGH) {
    // Door is open (magnet away)
    digitalWrite(lightPin, LOW);
    // Turn ON light
  } else {
    // Door is closed (magnet near)
      digitalWrite(lightPin, HIGH);
  }
}
