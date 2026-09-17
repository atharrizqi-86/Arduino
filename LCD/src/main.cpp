#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Insert text");
  Serial.println("Insert text");
}

void loop() {
  if (Serial.available() > 0) {
    // Baca baris teks dari Serial Monitor hingga karakter newline
    String input = Serial.readStringUntil('\n');
    input.trim(); 

    if (input.length() > 0) {
      lcd.clear();

      // Jika teks muat di baris pertama
      if (input.length() <= 16) {
        lcd.setCursor(0, 0);
        lcd.print(input);
      } 
      // Jika teks lebih panjang, pecah ke baris kedua
      else {
        String line1 = input.substring(0, 16);
        String line2 = input.substring(16, 16 * 2);

        lcd.setCursor(0, 0);
        lcd.print(line1);

        lcd.setCursor(0, 1);
        lcd.print(line2);
      }

      Serial.print("Ditampilkan: ");
      Serial.println(input);
    }
  }
}