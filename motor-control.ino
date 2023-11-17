#define PIN A0

#include "functions.h"

void setup()
{
    Serial.begin(115200);
    rfid_start();
    Serial.println(F("Aproxime um cartão RFID para leitura."));
}

void loop()
{
    rfid_read();
}
