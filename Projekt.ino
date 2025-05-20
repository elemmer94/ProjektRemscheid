#include "assets/classes/UsefullMethods.h"
#include "assets/classes/Sensors.h"

class Main
{
    /******** LEDs ********/
    // LED 
    int ledPin = 13;
    bool ledState = false;
    // LED2

    // LED3
    /****** Sensoren ******/
    // Infrarot Sensor
    int infraredSensorPin = 0;
    int infraredSensorValue;
    // Ultraschall Sensor
    int ultrasonicSensorPin = 1;
    int ultrasonicSensorValue;

    /**** Sekunden ****/
    unsigned long previousMillis = 0;
    const long standardInterval = 1000;

    /**** Objekte ****/
    UsefullMethods um;
    Sensors s;
    void setup()
    {
        pinMode(ledPin, OUTPUT);
        pinMode(infraredSensorPin, INPUT);
        pinMode(ultrasonicSensorPin, INPUT);
        Serial.begin(115200);
    }

    void loop()
    {
        if(um.delayWithoutDelay(previousMillis,standardInterval)){
            ledState ? ledState = false : ledState = true;
        }

        // Ausführung
        action();
    }
        
    void action()
    {
        digitalWrite(ledPin,ledState);
    }
};