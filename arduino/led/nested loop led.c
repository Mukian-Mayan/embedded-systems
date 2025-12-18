int pins[] = {7, 8, 9, 10, 11}; // Array of the pins
int numPins = 5;

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Move Forward
  for (int i = 0; i < numPins; i++) {
    digitalWrite(pins[i], HIGH);
    delay(80);
    digitalWrite(pins[i], LOW);
  }
  
  // Move Backward
  for (int i = numPins - 2; i > 0; i--) {
    digitalWrite(pins[i], HIGH);
    delay(80);
    digitalWrite(pins[i], LOW);
  }
}