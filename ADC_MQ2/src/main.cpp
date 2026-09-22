#include <Arduino.h>

const int MQ2_PIN = A0;

const float VREF = 5.0;
const int ADC_RESOLUTION = 1023;

void setup() {

  Serial.begin(115200);
  while (!Serial) {
    ; 
  }

  Serial.println("ADC MQ-2");
  delay(1000);
}

void loop() {
  // Membaca nilai mentah ADC (0 - 1023)
  int rawADC = analogRead(MQ2_PIN);

  // Mengonversi nilai ADC ke tegangan (Volt)
  float voltage = (rawADC * VREF) / ADC_RESOLUTION;

  // Menghitung persentase skala pembacaan
  float percentage = (rawADC / (float)ADC_RESOLUTION) * 100.0;

  // Kirim data ke Serial Port
  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  Serial.print(" | Tegangan: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Skala: ");
  Serial.print(percentage, 1);
  Serial.println("%");

  delay(500);
}