#include "functions.h"
#include "const.h"

void setup()
{
    pinMode(TEMPERATURE_SENSOR_PIN, INPUT);
    Serial.begin(115200);
    rfid_start();
    Serial.println(F("Aproxime um cartão RFID para leitura."));
}

void loop()
{
    rfid_read();
    temperature_read();
}
