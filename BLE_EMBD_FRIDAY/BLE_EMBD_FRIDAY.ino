#include <BluetoothSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <HardwareSerial.h>

// Initialize Bluetooth and DFPlayer
BluetoothSerial SerialBT;
HardwareSerial myDFSerial(1);  // UART1 for DFPlayer
DFRobotDFPlayerMini myDFPlayer;

// Relay connected to GPIO25
const int relayPin = 26;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Embedded-FRIDAY");  // Bluetooth device name

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Light OFF by default

  // Delay for DFPlayer to stabilize
  delay(1000);  
  myDFSerial.begin(9600, SERIAL_8N1, 16, 17); // RX, TX

  // Initialize DFPlayer
  if (!myDFPlayer.begin(myDFSerial)) {
    Serial.println("⚠ DFPlayer not responding!");
    while (1);
  }

  myDFPlayer.volume(30);  // Set volume

  // Play startup audio
  myDFPlayer.play(2); // 0002.mp3 - "System booting"
  delay(3500);
  myDFPlayer.play(1); // 0001.mp3 - "Welcome Boss"
  delay(4000);

  Serial.println("✅ Embedded FRIDAY is ready!");
}

void loop() {
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();
    cmd.toLowerCase();

    Serial.println("📲 Command received: " + cmd);

    if (cmd == "light on") {
      digitalWrite(relayPin, HIGH);
      myDFPlayer.play(3); // 🔊 "Turning on the light"
      SerialBT.println("✅ Light is ON");
    } 
    else if (cmd == "light off") {
      digitalWrite(relayPin, LOW);
      myDFPlayer.play(4); // 🔊 "Turning off the light"
      SerialBT.println("✅ Light is OFF");
    } 
    else if (cmd == "greet") {
      myDFPlayer.play(5); // 🔊 Greeting
      SerialBT.println("🎤 Greeting played");
    } 
    else if (cmd == "greet stop") {
      myDFPlayer.stop(); // 🔇 Stop audio
      SerialBT.println("⛔ Greeting stopped");
    } 
    else if (cmd == "alert") {
      myDFPlayer.play(6); // 🚨 Alert sound
      SerialBT.println("🚨 Alert played");
    } 
    else {
      SerialBT.println("❓ Unknown command: " + cmd);
    }
  }
}
