#include <ESP32Servo.h>

#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 13

#define ENA 25
#define ENB 33

#define TRIG 32
#define ECHO 34
#define SERVO_PIN 18   // FIXED

int speedForward = 80;
int speedTurn = 800;

Servo myServo;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  ledcAttach(ENA, 1000, 8);
  ledcAttach(ENB, 1000, 8);

  myServo.attach(SERVO_PIN);
  myServo.write(90);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  ledcWrite(ENA, speedForward);
  ledcWrite(ENB, speedForward);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  ledcWrite(ENA, speedTurn);
  ledcWrite(ENB, speedForward);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  ledcWrite(ENA, speedForward);
  ledcWrite(ENB, speedTurn);
}

void stopMotor() {
  ledcWrite(ENA, 0);
  ledcWrite(ENB, 0);
}

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  return duration * 0.034 / 2;
}

void loop() {
  long d = getDistance();

  if (d > 20 || d == 0) {
    forward();
  } else {
    stopMotor();
    delay(200);

    myServo.write(150);
    delay(400);
    long leftD = getDistance();

    myServo.write(30);
    delay(400);
    long rightD = getDistance();

    myServo.write(90);

    if (leftD > rightD) left();
    else right();

    delay(400);
  }
}
