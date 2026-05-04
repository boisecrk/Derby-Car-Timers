#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 3 separate LCDs (different I2C addresses required)
LiquidCrystal_I2C lcd1(0x26, 16, 2);
LiquidCrystal_I2C lcd2(0x25, 16, 2);
LiquidCrystal_I2C lcd3(0x27, 16, 2);

// buttons
const int startPin = 2;
const int stopPins[3] = {3, 4, 5};
const int resetPin = 6;

// timing
unsigned long startTime = 0;
unsigned long laneTime[3] = {0, 0, 0};
bool finished[3] = {false, false, false};
bool running = false;

// debounce tracking
bool lastStart = HIGH;
bool lastReset = HIGH;
bool lastStop[3] = {HIGH, HIGH, HIGH};

LiquidCrystal_I2C* lcds[3] = {&lcd1, &lcd2, &lcd3};

void setup() {
  Wire.begin();

  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();
  lcd3.init(); lcd3.backlight();

  pinMode(startPin, INPUT);
  pinMode(resetPin, INPUT_PULLUP);

  for (int i = 0; i < 3; i++) {
    pinMode(stopPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 3; i++) {
    lcds[i]->setCursor(0, 0);
    lcds[i]->print("READY LANE ");
    lcds[i]->print(i + 1);
  }
}

void loop() {
  unsigned long now = millis();

  // ---------- START ----------
  bool startState = digitalRead(startPin);
  if (lastStart == HIGH && startState == LOW && !running) {
    running = true; 
    startTime = now;

    for (int i = 0; i < 3; i++) {
      finished[i] = false;
      laneTime[i] = 0;
      lcds[i]->clear();
    }
  }
  lastStart = startState;

  // ---------- RESET ----------
  bool resetState = digitalRead(resetPin);
  if (lastReset == HIGH && resetState == LOW) {
    running = false;

    for (int i = 0; i < 3; i++) {
      finished[i] = false;
      laneTime[i] = 0;
      lcds[i]->clear();
      lcds[i]->setCursor(0, 0);
      lcds[i]->print("READY LANE ");
      lcds[i]->print(i + 1);
    }
  }
  lastReset = resetState;

  // ---------- LANES ----------
  if (running) {
    for (int i = 0; i < 3; i++) {
      bool stopState = digitalRead(stopPins[i]);

      if (lastStop[i] == HIGH && stopState == LOW && !finished[i]) {
        laneTime[i] = now - startTime;
        finished[i] = true;
      }

      lastStop[i] = stopState;
    }
  }

  displayAll();
}

void displayAll() {
  for (int i = 0; i < 3; i++) {
    lcds[i]->setCursor(0, 0);
    lcds[i]->print("LANE ");
    lcds[i]->print(i + 1);

    lcds[i]->setCursor(0, 1);
    printTime(*lcds[i], laneTime[i]);
  }
}

void printTime(LiquidCrystal_I2C &lcd, unsigned long t) {
  unsigned int sec = t / 1000;
  unsigned int ms = (t % 1000) / 10;

  if (sec < 10) lcd.print("0");
  lcd.print(sec);
  lcd.print(".");

  if (ms < 10) lcd.print("0");
  lcd.print(ms);
}