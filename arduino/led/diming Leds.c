int pins[] = {3, 5, 9, 10, 11}; // Array of the pins
int numPins = 5;

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Fade ALL pins UP
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(3, brightness);  
    analogWrite(5, brightness);  
    analogWrite(9, brightness);
    analogWrite(10, brightness);
    analogWrite(11, brightness);
    delay(5);
  }

  // Fade ALL pins DOWN
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(3, brightness);
    analogWrite(5, brightness);
    analogWrite(9, brightness);
    analogWrite(10, brightness);
    analogWrite(11, brightness);
    delay(5);
  }
}