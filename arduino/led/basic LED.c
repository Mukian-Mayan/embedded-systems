#include <arduino.h>

#define RG0 7     //red green combo
#define R1 8      // red led 1
#define G1 9      // green led 1
#define R2 10
#define G2 11



void setup() {
  pinMode (RG0 , OUTPUT);
  pinMode (R1 , OUTPUT);
  pinMode (G1 , OUTPUT);
  pinMode (R2 , OUTPUT);
  pinMode (G2 , OUTPUT);
}

void loop() {

  digitalWrite (RG0 ,1);
  delay (100);
  digitalWrite (RG0 ,0);
  delay (100);

  digitalWrite (R1 ,1);
  delay (100);
  digitalWrite (R1 ,0);
  delay (100);

  digitalWrite (G1 ,1);
  delay (100);
  digitalWrite (G1 ,0);
  delay (100);

  digitalWrite (R2 ,1);
  delay (100);
  digitalWrite (R2 ,0);
  delay (100);

  digitalWrite (G2 ,1);
  delay (100);
  digitalWrite (G2 ,0);
  delay (100);
}
