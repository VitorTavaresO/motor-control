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

    uint8_t data[5] = {
        read_motor_temperature(),
        read_fuel(),
        read_oil_temperature(),
        read_motor_rpm(),
        read_battery_voltage()};

    write_rasp(data, 5);
    delay(1000);
}