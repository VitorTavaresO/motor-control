#include <const.h>
#include <read_sensor.h>
#include <write_rasp.h>

void setup()
{
    pinMode(TEMPERATURE_PIN, INPUT);
    pinMode(FUEL_PIN, INPUT);
    pinMode(OIL_TEMPERATURE_PIN, INPUT);
    pinMode(MOTOR_RPM_PIN, INPUT);
    pinMode(BATTERY_VOLTAGE_PIN, INPUT);
    // Serial.begin(SerialRasp);
    Serial.begin(SerialDebug);
}
void loop()
{

    uint8_t data[5] = {
        read_motor_temperature(),
        read_fuel(),
        read_oil_temperature(),
        read_motor_rpm(),
        read_battery_voltage()};

    Serial.println("Hello World!");

    write_rasp(data, 5);
    delay(5000);
}