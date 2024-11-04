#include <const.h>
#include <read_sensor.h>

uint8_t read_motor_temperature()
{
    return map(analogRead(TEMPERATURE_PIN), 0, TEMPERATURE_MAX, 120, 0);
}

uint8_t read_fuel()
{
    return map(analogRead(FUEL_PIN), 0, 1023, 0, 255);
}

uint8_t read_oil_temperature()
{
    return map(analogRead(OIL_TEMPERATURE_PIN), 0, 1023, 0, 58);
}

uint8_t read_motor_rpm()
{
    return map(analogRead(MOTOR_RPM_PIN), 0, 1023, 0, 5800);
}

uint8_t read_battery_voltage()
{
    return map(analogRead(BATTERY_VOLTAGE_PIN), 0, 1023, 0, 100);
}
