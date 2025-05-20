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


/******** Funktionen ********/
void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(infraredSensorPin, INPUT);
    pinMode(ultrasonicSensorPin, INPUT);
    Serial.begin(115200);
}

void loop()
{
    if(delayWithoutDelay(standardInterval)){
        ledState ? ledState = false : ledState = true;
    }

    // Ausführung    
    action();
}

void action()
{
    digitalWrite(ledPin,ledState);
}

// Delayschleife ohne Delay
bool delayWithoutDelay(const long interval)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        return true;
    }else
    {
        return false;
    }
}
