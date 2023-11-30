#include <cstdint>

uint16_t max_temperature = 102;


uint16_t temperature_read(){
    uint16_t temperature_read = analogRead();

    temperature_read = map(temperature_read, max_temperature, 0, 0, 100);

    return temperature_read;
}
