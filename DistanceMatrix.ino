#include <LedControl.h>

// MAX7219 pins
#define DIN 11
#define CS 10
#define CLK 13

// Ultrasonic sensor pins
#define TRIG_PIN 7
#define ECHO_PIN 6

LedControl lc = LedControl(DIN, CLK, CS, 1); // 1 matrix

void setup() {
  Serial.begin(9600);

  // Initialize MAX7219
  lc.shutdown(0, false);    // Wake up
  lc.setIntensity(0, 8);    // Brightness (0-15)
  lc.clearDisplay(0);

  // Ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Read distance
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Map distance (0–30 cm → 8 rows)
  int ledRows = map(distance, 0, 30, 8, 0); 
  if (ledRows < 0) ledRows = 0;
  if (ledRows > 8) ledRows = 8;

  // Display bar graph (bottom to top)
  lc.clearDisplay(0);
  for (int row = 0; row < ledRows; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, 7 - row, col, true);  // bottom = row 7
    }
  }

  delay(200);
}
