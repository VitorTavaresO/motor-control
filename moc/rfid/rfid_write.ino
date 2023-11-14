#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 5
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

void setup() {
    Serial.begin(115200);
    while (!Serial);
    SPI.begin();
    mfrc522.PCD_Init();

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

    Serial.println(F("Aproxime um cartão RFID para escrita."));
}

void loop() {
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    byte blockAddr = 4;
    byte trailerBlock = 7;
    MFRC522::StatusCode status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Falha na autenticação: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    byte dataBlock[] = {
        0x01, 0x02, 0x03, 0x04,
        0x05, 0x06, 0x07, 0x08,
        0x09, 0x0A, 0x0B, 0x0C,
        0x0D, 0x0E, 0x0F, 0x10
    };

    status = mfrc522.MIFARE_Write(blockAddr, dataBlock, 16);

    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("Falha na escrita: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
    } else {
        Serial.print(F("Dados escritos no bloco ")); Serial.println(blockAddr);
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  
    delay(2000);
}

void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}