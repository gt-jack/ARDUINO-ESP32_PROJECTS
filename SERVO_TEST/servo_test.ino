#include <Servo.h>

Servo myservo;   // create servo object

void setup() {
  myservo.attach(9);  // Servo signal wire connected to pin 9
}

void loop() {
  // Move from 0° to 180°
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(15);  // 15ms delay for smooth movement
  }

  // Move from 180° to 0°
  for (int pos = 180; pos >= 0; pos--) {
    myservo.write(pos);
    delay(15);
  }
}
