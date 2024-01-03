#include <stdint.h>
#include <Arduino.h>
#include "const.h"

uint16_t max_temperature = 1023;


uint16_t temperature_read(){
    uint16_t temperature_read = analogRead(TEMPERATURE_SENSOR_PIN);

    temperature_read = map(temperature_read, max_temperature, 0, 0, 100);

    return temperature_read;
}
