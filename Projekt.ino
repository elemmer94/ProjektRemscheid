#include "BrauchbareMethoden.h"
#include "GetSensor.h"

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

    usefullMethods um;

    void setup()
    {
        pinMode(ledPin, OUTPUT);
        pinMode(infraredSensorPin, INPUT);
        pinMode(ultrasonicSensorPin, INPUT);
        Serial.begin(115200);
    }

    void loop()
    {
        //if(delayWithoutDelay(previousMillis,standardInterval)){
        //    ledState ? ledState = false : ledState = true;
        //}

        // Ausführung
        um.testung();
    }
};
