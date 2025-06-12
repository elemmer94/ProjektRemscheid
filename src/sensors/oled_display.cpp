#include "oled_display.h"
#include <Wire.h>
#include "mqtt_client.h"

OLedDisplay::OLedDisplay(uint8_t sckPin, uint8_t sdaPin, uint8_t relaisPin, const char *responseTopic)
    : _sckPin(sckPin), _sdaPin(sdaPin), _relaisPin(relaisPin), _responseTopic(responseTopic) {}

int counter = 5;

void OLedDisplay::begin()
{
    u8g2 = new U8G2_SH1106_128X64_NONAME_F_SW_I2C(U8G2_R0, _sckPin, _sdaPin, U8X8_PIN_NONE);
    subscribeToTopic(_responseTopic, [this](const String &message)
                     { handleAccessResponse(message); });

    u8g2->begin();
    Serial.println("🟢 OLED-Display bereit.");

    pinMode(_relaisPin, OUTPUT);
    Serial.println("🟢 Relais bereit.");
}

void OLedDisplay::loop()
{
    u8g2->clearBuffer();
    u8g2->sendBuffer();
}

void OLedDisplay::handleAccessResponse(const String &message)
{
    u8g2->clearBuffer();
    u8g2->setFont(u8g2_font_ncenB14_tf);

    if (message == "granted")
    {
        Serial.println("Zugang genehmigt!");
        u8g2->drawStr(24, 24, "Zugang");
        u8g2->drawStr(12, 54, "genehmigt!");
        u8g2->sendBuffer();
        digitalWrite(_relaisPin, HIGH);

        counter = 5;

        delay(2000);
    }
    else if (message == "denied")
    {
        Serial.println("Zugang verboten!");
        u8g2->drawStr(24, 24, "Zugang");
        u8g2->drawStr(18, 54, "verboten!");
        u8g2->sendBuffer();
        counter = 5;
    }
    else if (message == "2factor")
    {
        Serial.println("2 Faktor Authentifizierung!");
        u8g2->drawStr(24, 24, "2 Faktor");
        u8g2->setFont(u8g2_font_ncenB10_tf);
        u8g2->drawStr(0, 54, "Authentifizierung");
        u8g2->sendBuffer();
    }
    else if(message == "countdown")
    {
        Serial.print("Countdown ");
        Serial.println(counter);
        u8g2->setFont(u8g2_font_ncenB24_tf);
        u8g2->drawStr(52, 48, String(counter).c_str());
        u8g2->sendBuffer();

        counter--;
        if(counter == 0)
        {
            counter = 5;
        }
    }
    else
    {
        Serial.println("Timeout");
        u8g2->setFont(u8g2_font_ncenB18_tf);
        u8g2->drawStr(9, 45, "Timeout");
        u8g2->sendBuffer();

        delay(500);
        u8g2->clearBuffer();
        u8g2->sendBuffer();

        Serial.println("Zugang verboten!");
        u8g2->setFont(u8g2_font_ncenB14_tf);
        u8g2->drawStr(24, 24, "Zugang");
        u8g2->drawStr(18, 54, "verboten!");
        u8g2->sendBuffer();
    }

    delay(500);
    digitalWrite(_relaisPin, LOW);
}
