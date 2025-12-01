#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

HardwareSerial mySerial(1);  // Use UART1

DFRobotDFPlayerMini dfplayer;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17

  Serial.println("Initializing DFPlayer Mini...");

  if (!dfplayer.begin(mySerial)) {
    Serial.println("Unable to communicate with DFPlayer Mini:");
    Serial.println("1. Check connection");
    Serial.println("2. Insert SD card");
    while (true);
  }

  Serial.println("DFPlayer Mini online!");

  dfplayer.volume(30); // Volume (0–30)
  dfplayer.randomAll();   
   //dfplayer.play(1); // Play 0001.mp3
}

void loop() {
  // You can control songs dynamically:
  // dfplayer.next();
  // dfplayer.previous();
  // dfplayer.pause();
  // dfplayer.start();
  // dfplayer.play(2);  // Plays 0002.mp3
}
