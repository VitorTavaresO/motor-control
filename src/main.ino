#include <Arduino.h>
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
    uint8_t data[5] = {analogRead(TEMPERATURE_PIN), analogRead(FUEL_PIN), analogRead(OIL_TEMPERATURE_PIN), analogRead(MOTOR_RPM), analogRead(BATTERY_VOLTAGE)};

    Serial.println("Temperature: " + data[0]);
    Serial.println("Fuel: " + data[1]);
    Serial.println("Oil Temperature: " + data[2]);
    Serial.println("Motor RPM: " + data[3]);
    Serial.println("Battery Voltage: " + data[4]);
    delay(1000);
}