#include <SoftwareSerial.h>
#include <ModbusMaster.h>

// Pin configuration
const uint8_t RS485_RX_PIN = 2;
const uint8_t RS485_TX_PIN = 3;
const uint8_t RS485_CONTROL_PIN = 4;

// Modbus configuration
const uint8_t SLAVE_ID = 1;
const uint16_t START_REGISTER = 1;
const uint16_t REGISTER_COUNT = 2;

SoftwareSerial rs485Serial(
  RS485_RX_PIN,
  RS485_TX_PIN
);

ModbusMaster node;

void preTransmission() {
  digitalWrite(RS485_CONTROL_PIN, HIGH);
}

void postTransmission() {
  digitalWrite(RS485_CONTROL_PIN, LOW);
}

void setup() {
  Serial.begin(9600);
  rs485Serial.begin(9600);

  pinMode(RS485_CONTROL_PIN, OUTPUT);
  digitalWrite(RS485_CONTROL_PIN, LOW);

  node.begin(SLAVE_ID, rs485Serial);

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  Serial.println("Start");
}

void loop() {
  uint8_t result = node.readInputRegisters(
    START_REGISTER,
    REGISTER_COUNT
  );

  if (result == node.ku8MBSuccess) {
    int16_t rawTemperature =
      (int16_t)node.getResponseBuffer(0);

    uint16_t rawHumidity =
      node.getResponseBuffer(1);

    float temperature = rawTemperature / 10.0;
    float humidity = rawHumidity / 10.0;

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %RH");

  } else {
    Serial.print("Modbus Error: ");
    Serial.println(result);
  }

  delay(2000);
}