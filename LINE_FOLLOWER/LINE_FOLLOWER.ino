#define IN1 26
#define IN2 27
#define IN3 14
#define IN4 13

#define ENA 25
#define ENB 33

#define IR_LEFT 34
#define IR_RIGHT 35

int speedForward = 80;
int speedTurn = 800;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  // NEW ESP32 PWM (Arduino core 3.x)
  ledcAttach(ENA, 1000, 8); // pin, frequency, resolution
  ledcAttach(ENB, 1000, 8);
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

void loop() {
  int L = digitalRead(IR_LEFT);
  int R = digitalRead(IR_RIGHT);

  if (L == 0 && R == 0) {
    forward();
  }
  else if (L == 1 && R == 0) {
    left();
  }
  else if (L == 0 && R == 1) {
    right();
  }
  else {
    stopMotor();
  }
}
