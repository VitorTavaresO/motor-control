#define PIN A0

void setup()
{
	Serial.begin(115200);
    pinMode(INPUT, INPUT);
}

void loop()
{
    Serial.println(analogRead(PIN));
    delay(1000);
}
