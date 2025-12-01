#define LED1 13   // First LED
#define LED2 12   // Second LED

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // LED 1 ON, LED 2 OFF
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(500);

  // LED 1 OFF, LED 2 ON
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(500);

  // LED 2 OFF before repeating
  digitalWrite(LED2, LOW);
}
