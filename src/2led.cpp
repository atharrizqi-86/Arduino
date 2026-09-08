#include <Arduino.h> // Library untuk Arduino

// Definisi pin LED
const int LED1_PIN = 2; // Pin 2
const int LED2_PIN = 3; // Pin 3

// Menetapkan const sebagai output
void setup() {  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

// Bagian utama bagaimana program bekerja
// Bergerak dimulai dari atas sampai selesai di bawah
// Setelah selesai program akan mengulang kembali dari awal 
void loop() {
  // Detik 1: LED1 nyala, LED2 nyala 
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  delay(1000); // Blocking 1000 ms (1 detik)

  // Detik 2: LED1 mati, LED2 tetap nyala
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, HIGH);
  delay(1000); 

  // Detik 3: LED1 nyala, LED2 mati
  digitalWrite(LED1_PIN, HIGH);
  digitalWrite(LED2_PIN, LOW);
  delay(1000); 

  // Detik 4: LED1 mati, LED2 Tetap mati
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  delay(1000); 
}