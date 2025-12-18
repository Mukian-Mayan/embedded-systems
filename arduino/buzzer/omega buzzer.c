/*
NORMAL CODE 

#include <Arduino.h>

#define BUZZER 8

int melody[] = {
  261, 261, 392, 392, 440, 440, 392, // Twinkle Twinkle Little Star
  349, 349, 329, 329, 294, 294, 261  // How I Wonder What You Are
};

int duration[] = {
  500, 500, 500, 500, 500, 500, 1000, 
  500, 500, 500, 500, 500, 500, 1000
};

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  for(int i=0; i<14; i++){
    if(melody[i] == 0) {
      noTone(BUZZER); // Rest
    } else {
      tone(BUZZER, melody[i], duration[i]);
    }
    delay(duration[i] + 50); // Wait for note + small pause
  }
}
*/

#include <avr/io.h>
#include <util/delay.h>

#define BUZZER PB0  // D8 on Arduino Uno

// Note frequencies (Hz)
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 329
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 493
#define NOTE_C5 523
#define REST 0

// Melody array
uint16_t melody[] = {
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// Note durations in ms
uint16_t duration[] = {
    500, 500, 500, 500, 500, 500, 1000,
    500, 500, 500, 500, 500, 500, 1000
};

#define MELODY_LENGTH (sizeof(melody)/sizeof(melody[0]))

// Function to play a tone
void play_tone(uint16_t frequency, uint16_t length_ms) {
    if(frequency == 0) {  // Rest
        _delay_ms(length_ms);
        return;
    }

    uint32_t half_period_us = 1000000 / frequency / 2;
    uint32_t cycles = (frequency * length_ms) / 1000;

    for(uint32_t i = 0; i < cycles; i++) {
        PORTB |= (1 << BUZZER);    // Set pin high
        _delay_us(half_period_us);
        PORTB &= ~(1 << BUZZER);   // Set pin low
        _delay_us(half_period_us);
    }
}

int main(void) {
    DDRB |= (1 << BUZZER);  // Set PB0 as output

    while(1) {
        for(uint8_t i = 0; i < MELODY_LENGTH; i++) {
            play_tone(melody[i], duration[i]);
            _delay_ms(50);  // short pause between notes
        }
    }
}


/*
JINGLE BELLS

#include <Arduino.h>

#define BUZZER 8

// Jingle Bells melody notes (frequencies in Hz)
int melody[] = {
  330, 330, 330, // E E E
  330, 330, 330, // E E E
  330, 392, 261, 294, 330, // E G C D E
  
  349, 349, 349, 349, // F F F F
  349, 330, 330, 330, 330, // F E E E E
  
  330, 330, 330, // E E E
  330, 294, 294, 330, 294, 392 // E D D E D G
};

// Note durations (milliseconds)
int duration[] = {
  400, 400, 800, // E E E
  400, 400, 800, // E E E
  400, 400, 400, 400, 800, // E G C D E

  400, 400, 400, 400, // F F F F
  400, 400, 400, 400, 800, // F E E E E

  400, 400, 800, // E E E
  400, 400, 400, 400, 400, 800 // E D D E D G
};

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int notes = sizeof(melody) / sizeof(melody[0]);

  for(int i = 0; i < notes; i++) {
    if(melody[i] == 0) {
      noTone(BUZZER); // Rest
    } else {
      tone(BUZZER, melody[i], duration[i]);
    }
    delay(duration[i] + 50); // Wait for note + small pause
  }

  delay(1000); // Pause before repeating
}

*/

/*
POLICE SIRENS 

#include <Arduino.h>

#define BUZZER 8

// Siren parameters
int lowFreq1 = 600;    // Low pitch for tone 1
int highFreq1 = 1200;  // High pitch for tone 1
int lowFreq2 = 800;    // Low pitch for tone 2
int highFreq2 = 1400;  // High pitch for tone 2

int step = 5;          // Frequency increment for smooth sweep
int delayTime = 4;     // Delay between frequency steps

void setup() {
  pinMode(BUZZER, OUTPUT);
}

// Function to sweep frequency up and down
void sweepSiren(int lowFreq, int highFreq) {
  // Sweep up
  for (int freq = lowFreq; freq <= highFreq; freq += step) {
    tone(BUZZER, freq);
    delay(delayTime);
  }
  // Sweep down
  for (int freq = highFreq; freq >= lowFreq; freq -= step) {
    tone(BUZZER, freq);
    delay(delayTime);
  }
}

void loop() {
  // Cycle 1: tone 1 smooth sweep
  sweepSiren(lowFreq1, highFreq1);
  
  // Short pause for realism
  noTone(BUZZER);
  delay(50);
  
  // Cycle 2: tone 2 smooth sweep
  sweepSiren(lowFreq2, highFreq2);
  
  // Alternate pattern: faster sweeps
  for (int i = 0; i < 2; i++) {
    sweepSiren(lowFreq1, highFreq1);
    sweepSiren(lowFreq2, highFreq2);
  }

  // Short rest before repeating the full siren pattern
  noTone(BUZZER);
  delay(200);
}

*/