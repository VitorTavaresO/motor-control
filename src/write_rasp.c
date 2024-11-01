#include <Arduino.h>
#include <HardwareSerial.h>

bool write_rasp(uint8_t *data, uint8_t size)
{
    Serial.write(data, size);
    return true;
}