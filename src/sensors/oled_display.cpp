#include "oled_display.h"
#include <Wire.h>
#include "mqtt_client.h"

OLedDisplay::OLedDisplay(uint8_t sckPin, uint8_t sdaPin, const char *responseTopic)
    : _sckPin(sckPin), _sdaPin(sdaPin), _responseTopic(responseTopic) {}

void OLedDisplay::begin()
{
    u8g2 = new U8G2_SH1106_128X64_NONAME_F_SW_I2C(U8G2_R0, _sckPin, _sdaPin, U8X8_PIN_NONE);
    u8g2->begin();
    u8g2->setFont(u8g2_font_ncenB14_tf);

    subscribeToTopic(_responseTopic, [this](const String &message)
                     { handleAccessResponse(message); });
}

void OLedDisplay::loop()
{
    u8g2->clearBuffer();
    u8g2->sendBuffer();
    delay(1000);
}

void OLedDisplay::handleAccessResponse(const String &message)
{
    u8g2->clearBuffer();

    if (message == "granted")
    {
        Serial.println("Zugang gewährt");
        u8g2->drawStr(24, 24, "Zugang");
        u8g2->drawStr(12, 54, "genehmigt!");
    }
    else
    {
        Serial.println("Zugang abgelehnt");
        u8g2->drawStr(24, 24, "Zugang");
        u8g2->drawStr(18, 54, "verboten!");
    }
    u8g2->sendBuffer();
}
