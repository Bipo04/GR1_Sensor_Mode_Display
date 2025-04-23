#include <LiquidCrystal.h>

const int rs_Pin = 19;
const int enable_Pin = 23;
const int d4_Pin = 18;
const int d5_Pin = 5;
const int d6_Pin = 17;
const int d7_Pin = 16;

const int button_Pin1 = 4;
const int button_Pin2 = 15;

const int IR_Pin = 25;
const int Touch_Pin = 26;

int buttonState1 = 0;
int buttonState2 = 0;
int irState = 0;
int touchState = 0;

LiquidCrystal lcd(rs_Pin, enable_Pin, d4_Pin, d5_Pin, d6_Pin, d7_Pin);

String currentMode = "Choose mode";
String state;

void setup() {
  lcd.begin(16, 2);
  lcd.print(currentMode);
  pinMode(button_Pin1, INPUT);
  pinMode(button_Pin2, INPUT);
  pinMode(IR_Pin, INPUT);
  pinMode(Touch_Pin, INPUT);
}

void loop() {
  buttonState1 = digitalRead(button_Pin1);
  buttonState2 = digitalRead(button_Pin2);

  if (buttonState1 == HIGH) {
    currentMode = "IR Mode        ";
    updateDisplay1();
    waitForButtonRelease();
    while1Mode();
  } else if (buttonState2 == HIGH) {
    currentMode = "Touch Mode     ";
    updateDisplay1();
    waitForButtonRelease();
    while2Mode();
  }
  delay(50);
}

void updateDisplay1() {
  lcd.setCursor(0, 0);
  lcd.print(currentMode);
}

void updateDisplay2() {
  lcd.setCursor(0, 1);
  lcd.print(state);
}

void waitForButtonRelease() {
  while (digitalRead(button_Pin1) == HIGH || digitalRead(button_Pin2) == HIGH) {
    delay(50);
  }
}

void while1Mode() {
  while (true) {
    buttonState1 = digitalRead(button_Pin1);
    buttonState2 = digitalRead(button_Pin2);
    delay(100);

    if (buttonState1 == HIGH || buttonState2 == HIGH) {
      currentMode = "Choose mode";
      lcd.clear();
      updateDisplay1();
      waitForButtonRelease();
      break;
    }

    irState = digitalRead(IR_Pin);
    state = irState ? "State: OFF      " : "State: ON       ";
    updateDisplay2();
  }
}

void while2Mode() {
  while (true) {
    buttonState1 = digitalRead(button_Pin1);
    buttonState2 = digitalRead(button_Pin2);
    delay(100);

    if (buttonState1 == HIGH || buttonState2 == HIGH) {
      currentMode = "Choose mode";
      lcd.clear();
      updateDisplay1();
      waitForButtonRelease();
      break;
    }

    touchState = digitalRead(Touch_Pin);
    state = touchState ? "State: OFF      " : "State: ON       ";
    updateDisplay2();
  }
}