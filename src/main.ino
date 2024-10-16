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

    Serial.write(data, sizeof(data));
    delay(1000);
}