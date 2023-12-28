#include <stdint.h>
#include <Arduino.h>

uint16_t max_temperature = 102;


uint16_t temperature_read(){
    uint16_t temperature_read = analogRead(A0);

    temperature_read = map(temperature_read, max_temperature, 0, 0, 100);

    return temperature_read;
}
