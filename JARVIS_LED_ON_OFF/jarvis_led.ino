void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);  // LED on pin 13
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == '1') {
      digitalWrite(13, HIGH);
    } else if (cmd == '0') {
      digitalWrite(13, LOW);
    }
  }
}
