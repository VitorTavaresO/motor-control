#include <Arduino.h>
#include <HardwareSerial.h>
#include <const.h>

void setup()
{
    pinMode(TEMPERATURE_PIN, INPUT);
    pinMode(FUEL_PIN, INPUT);
    pinMode(OIL_TEMPERATURE_PIN, INPUT);
    pinMode(MOTOR_RPM, INPUT);
    pinMode(BATTERY_VOLTAGE, INPUT);
    Serial.begin(SerialRasp);
}
void loop()
{
    uint8_t motor_temperature = map(analogRead(TEMPERATURE_PIN), 0, 1023, 0, 255);
    uint8_t fuel = map(analogRead(FUEL_PIN), 0, 1023, 0, 255);
    uint8_t oil_temperature = map(analogRead(OIL_TEMPERATURE_PIN), 0, 1023, 0, 58);
    uint8_t motor_rpm = map(analogRead(MOTOR_RPM), 0, 1023, 0, 5800);
    uint8_t battery_voltage = map(analogRead(BATTERY_VOLTAGE), 0, 1023, 0, 100);
    uint8_t data[5] = {motor_temperature, fuel, oil_temperature, motor_rpm, battery_voltage};

    Serial.write(data, sizeof(data));
    delay(1000);
}