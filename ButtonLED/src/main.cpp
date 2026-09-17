#include <Arduino.h>

const int PIN_BUTTON = 2;
const int PIN_LED = 13;

int statusLed = LOW;
int kondisiTombolTerakhir = LOW; 

void setup() {
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, statusLed);
}

void loop() {
  int kondisiTombol = digitalRead(PIN_BUTTON);
  
  if (kondisiTombolTerakhir == HIGH && kondisiTombol == LOW) {
    statusLed = !statusLed;               
    digitalWrite(PIN_LED, statusLed);    
  }

  kondisiTombolTerakhir = kondisiTombol;
}