#include <Arduino.h>

const int LED1_PIN = 2;
const int LED2_PIN = 3;

// Interval waktu (dalam milidetik)
const unsigned long INTERVAL_LED1 = 1000; // 1 detik
const unsigned long INTERVAL_LED2 = 2000; // 2 detik

// Variabel penyimpan waktu terakhir LED berubah status
unsigned long previousMillisLED1 = 0;
unsigned long previousMillisLED2 = 0;

// Variabel penyimpan status LED saat ini
int ledState1 = LOW;
int ledState2 = LOW;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Penanganan LED 1 (kedip tiap 1 detik)
  if (currentMillis - previousMillisLED1 >= INTERVAL_LED1) {
    previousMillisLED1 = currentMillis; // Perbarui catatan waktu
    ledState1 = !ledState1;             // Toggle status LED (HIGH <-> LOW)
    digitalWrite(LED1_PIN, ledState1);
  }

  // Penanganan LED 2 (kedip tiap 2 detik)
  if (currentMillis - previousMillisLED2 >= INTERVAL_LED2) {
    previousMillisLED2 = currentMillis; // Perbarui catatan waktu
    ledState2 = !ledState2;             // Toggle status LED (HIGH <-> LOW)
    digitalWrite(LED2_PIN, ledState2);
  }
}