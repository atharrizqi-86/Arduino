#include <Arduino.h>

const int SENSOR_PIN = A0;

const float VCC = 5.0;     
const int ADC_RESOLUTION = 1023;  
const float RESISTOR_VAL = 270.0; 

void setup() {
    Serial.begin(115200);
    pinMode(SENSOR_PIN, INPUT);
    Serial.println("RK510-01 Start");
}

void loop() {
    int adcValue = analogRead(SENSOR_PIN);
    float voltage = (adcValue / (float)ADC_RESOLUTION) * VCC;
    
    // Tegangan ke Arus
    float currentmA = (voltage / RESISTOR_VAL) * 1000.0;
    
    float soilMoisture = ((currentmA - 4.0) / (20.0 - 4.0)) * 100.0;
    
    // Batas
    if (soilMoisture > 100.0) soilMoisture = 100.0;
    if (soilMoisture < 0.0) soilMoisture = 0.0;
   
    Serial.print("Raw ADC: ");
    Serial.print(adcValue);
    Serial.print(" | Volt: ");
    Serial.print(voltage, 2);
    Serial.print("V | Current: ");
    Serial.print(currentmA, 2);
    Serial.print(" mA | Moisture: ");
    Serial.print(soilMoisture, 1);
    Serial.println("%");

    delay(100); // Sampling 10 Hz
}
