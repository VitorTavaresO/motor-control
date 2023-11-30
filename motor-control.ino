#include "functions.h"

#define TEMPERATURE_SENSOR_PIN A0
#define RST_PIN 5
#define SS_PIN 10


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
