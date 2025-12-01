// === 7-Segment Display: Count 0–9 ===
// Works with common cathode display

// Segment pins: a, b, c, d, e, f, g
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};

// Digit patterns for numbers 0–9
// 1 = segment ON, 0 = segment OFF
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int num = 0; num <= 9; num++) {
    displayDigit(num);
    delay(100);  // Show each number for 1 second
  }
}

void displayDigit(int num) {
  for (int seg = 0; seg < 7; seg++) {
    digitalWrite(segmentPins[seg], digits[num][seg]);
  }
}
