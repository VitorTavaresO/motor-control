#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
}
void loop()
{
    Serial.println("Dados para o Raspberry Pi");
    delay(1000);
}