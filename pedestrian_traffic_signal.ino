// ===== Pin definitions =====

// Car traffic lights
const int CAR_RED    = 11;
const int CAR_YELLOW = 10;
const int CAR_GREEN  = 9;

// Pedestrian lights
const int PED_RED   = 13;
const int PED_WALK  = 12;   // white LED

// Button (wired to GND, use INPUT_PULLUP)
const int BUTTON_PIN = 2;

// 7-seg segment pins (COMMON CATHODE), using your tested mapping:
const int SEG_A = 5;   // top
const int SEG_B = A1;  // top-right
const int SEG_C = 8;   // bottom-right
const int SEG_D = 3;   // bottom
const int SEG_E = 4;   // bottom-left
const int SEG_F = 6;   // top-left
const int SEG_G = 7;   // middle

const int segmentPins[7] = {
  SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G
};

// Digit patterns for 0–9 (order: a b c d e f g ; 1 = ON, 0 = OFF)
const byte DIGITS[10][7] = {
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

// ===== Setup =====
void setup() {
  // Traffic light pins
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_WALK, OUTPUT);

  // Button
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // button between pin 2 and GND

  // 7-seg segments
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  // Start: cars green, pedestrians red, display off
  digitalWrite(CAR_GREEN, HIGH);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_RED, LOW);

  digitalWrite(PED_RED, HIGH);
  digitalWrite(PED_WALK, LOW);

  clearDisplay();
}

// ===== Main loop =====
void loop() {
  // Normal state: cars green, pedestrians red
  digitalWrite(CAR_GREEN, HIGH);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_RED, LOW);

  digitalWrite(PED_RED, HIGH);
  digitalWrite(PED_WALK, LOW);
  clearDisplay();

  // Wait for button press
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(40); // debounce
    if (digitalRead(BUTTON_PIN) == LOW) {
      runCrossingCycle();

      // Wait for button release so it doesn't immediately re-trigger
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
    }
  }

  delay(30);  // small pause between checks
}

// ===== Crossing sequence =====
void runCrossingCycle() {
  // 1) Cars: GREEN -> YELLOW
  digitalWrite(CAR_GREEN, LOW);
  digitalWrite(CAR_YELLOW, HIGH);
  digitalWrite(CAR_RED, LOW);
  delay(2000);   // 2 seconds yellow

  // 2) Cars: YELLOW -> RED
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_RED, HIGH);
  delay(1000);   // 1 second all-red before walk

  // 3) Pedestrians WALK
  digitalWrite(PED_RED, LOW);
  digitalWrite(PED_WALK, HIGH);

  // Countdown 5 → 0
  for (int n = 9; n >= 0; n--) {
    displayDigit(n);
    delay(1000);   // 1 second per number
  }

  // 4) Clear display, blink WALK as final warning
  clearDisplay();
  for (int i = 0; i < 3; i++) {
    digitalWrite(PED_WALK, LOW);
    delay(300);
    digitalWrite(PED_WALK, HIGH);
    delay(300);
  }

  // 5) Pedestrians back to STOP
  digitalWrite(PED_WALK, LOW);
  digitalWrite(PED_RED, HIGH);
  clearDisplay();
  delay(1000);

  // 6) Cars back to GREEN
  digitalWrite(CAR_RED, LOW);
  digitalWrite(CAR_GREEN, HIGH);
}

// ===== 7-seg helper functions =====
void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}

void displayDigit(int number) {
  if (number < 0 || number > 9) {
    clearDisplay();
    return;
  }
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], DIGITS[number][i] ? HIGH : LOW);
  }
}
