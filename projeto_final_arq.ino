#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int buzzerPin = 10;

const int noteFrequencies[16] = {
  261, 294, 329, 349,
  392, 440, 493, 523,
  587, 659, 698, 784,
  880, 987, 1046, 1175
};

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.println(key);
        
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (keys[i][j] == key) {
          
          int noteIndex = i * COLS + j;
          
          tone(buzzerPin, noteFrequencies[noteIndex], 200);
        }
      }
    }
  }
}