#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin data DS18B20 dihubungkan ke pin 2 Arduino
const int ONE_WIRE_BUS = 2;

// Inisialisasi OneWire dan DS18B20
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  Serial.println("Inisialisasi DS18B20 selesai.");
}

void loop() {
  // Kirim perintah untuk mengukur suhu ke semua sensor di bus
  sensors.requestTemperatures(); 

  // Ambil suhu dalam Celcius dari sensor indeks ke-0 (sensor pertama)
  float tempC = sensors.getTempCByIndex(0);

  // Cek apakah pembacaan valid
  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor DS18B20 tidak terdeteksi!");
  } else {
    Serial.print("Suhu: ");
    Serial.print(tempC);
    Serial.println(" °C");
  }

  delay(1000); // Pembacaan setiap 1 detik
}