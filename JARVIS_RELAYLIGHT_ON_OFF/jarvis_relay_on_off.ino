const int relayPin = 7;   // Relay control pin
const int ledPin = 8;     // LED control pin
void setup() 
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  // Start with everything OFF
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);
}
void loop() 
{
  if (Serial.available()) 
  {
    String command = Serial.readStringUntil('\n');
    command.trim();  // Remove whitespace/newline

    if (command == "ON")
    {
      digitalWrite(relayPin, HIGH);  // Turn relay ON
      digitalWrite(ledPin, HIGH);    // Turn LED ON
    } 
    else if (command == "OFF") 
    {
      digitalWrite(relayPin, LOW);   // Turn relay OFF
      digitalWrite(ledPin, LOW);     
    }
  }
}
