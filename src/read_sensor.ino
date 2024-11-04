#include <const.h>
#include <read_sensor.h>

uint8_t read_motor_temperature()
{
    return map(analogRead(TEMPERATURE_PIN), 0, 690, TEMPERATURE_MAX, 0);
}

uint8_t read_fuel()
{
    return map(analogRead(FUEL_PIN), 0, 1023, 0, FUEL_MAX);
}

uint8_t read_oil_pression()
{
    return map(analogRead(OIL_PRESSION_PIN), 0, 1023, 0, 1);
}

uint8_t read_motor_rpm()
{
    return map(analogRead(MOTOR_RPM_PIN), 0, 1023, 0, 5800);
}

uint8_t read_battery_voltage()
{
    return map(analogRead(BATTERY_VOLTAGE_PIN), 0, 1023, 0, 100);
}
