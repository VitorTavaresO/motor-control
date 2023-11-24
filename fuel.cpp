#define FUEL_PIN 15

void fuel_print(){
    int fuel = map(analogRead(FUEL_PIN), 1023, 0, 0, 100);
    Serial.print("Fuel: ");
    Serial.print(fuel);
}