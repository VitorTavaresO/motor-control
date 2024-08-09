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
    Serial.println("Dados para o Raspberry Pi");
    delay(1000);
}