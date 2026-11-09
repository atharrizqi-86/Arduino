#include <Arduino.h>

const int ANALOG = A0;

const float VREF = 5.0;
const int ADC_RESOLUTION = 1023;
const int PERCENT = 100;

void setup() {

  Serial.begin(115200);
  while (!Serial) {
    ; 
  }

  Serial.println("KELEMBAPAN TANAH");
  delay(1000);
}

void loop() {
  // Membaca nilai mentah ADC (0 - 1023)
  int rawADC = analogRead(ANALOG);

  // Mengonversi nilai ADC ke tegangan (Volt)
  float voltage = (rawADC * VREF) / ADC_RESOLUTION;

  // Menghitung persentase skala pembacaan
  float percentage = (rawADC / (float)ADC_RESOLUTION) * PERCENT;

  // Kirim data ke Serial Port
  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  Serial.print(" | Tegangan: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Skala: ");
  Serial.print(percentage, 1);
  Serial.println("%");

  delay(100);
}