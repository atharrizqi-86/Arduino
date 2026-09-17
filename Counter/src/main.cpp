#include <Arduino.h>

const int PIN_BUTTON = 9;

// pin a, b, c, d, e, f, g
const int pinSegmen[7] = {2, 3, 4, 5, 6, 7, 8};

// Indeks bit: a, b, c, d, e, f, g
const byte polaAngka[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 0
  {LOW,  HIGH, HIGH, LOW,  LOW,  LOW,  LOW},  // 1
  {HIGH, HIGH, LOW,  HIGH, HIGH, LOW,  HIGH}, // 2
  {HIGH, HIGH, HIGH, HIGH, LOW,  LOW,  HIGH}, // 3
  {LOW,  HIGH, HIGH, LOW,  LOW,  HIGH, HIGH}, // 4
  {HIGH, LOW,  HIGH, HIGH, LOW,  HIGH, HIGH}, // 5
  {HIGH, LOW,  HIGH, HIGH, HIGH, HIGH, HIGH}, // 6
  {HIGH, HIGH, HIGH, LOW,  LOW,  LOW,  LOW},  // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW,  HIGH, HIGH}  // 9
};

int counter = 0;
int tombolTerakhir = HIGH;

void tampilkanAngka(int angka) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pinSegmen[i], polaAngka[angka][i]);
  }
}

void setup() {
  
  for (int i = 0; i < 7; i++) {
    pinMode(pinSegmen[i], OUTPUT);
  }

  pinMode(PIN_BUTTON, INPUT_PULLUP);

  // angka awal (0)
  tampilkanAngka(counter);
}

void loop() {
  int tombolSekarang = digitalRead(PIN_BUTTON);
  // Deteksi transisi tombol ditekan (HIGH -> LOW)
  if (tombolTerakhir == HIGH && tombolSekarang == LOW) {
    counter++;
    if (counter > 9) {
      counter = 0; // Reset kembali ke 0 setelah 9
    }
    tampilkanAngka(counter);
  }

  tombolTerakhir = tombolSekarang;
}