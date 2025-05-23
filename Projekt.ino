#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "assets/classes/UsefullMethods.h"
#include "assets/classes/Sensors.h"

/******** LEDs ********/
// LED 
int ledPin = 13;
bool ledState = false;
// LED2

// LED3

/****** Sensoren ******/
// Infrarot Sensor
int infraredSensorPin = D0;
int infraredSensorValue;
// Ultraschall Sensor
int ultrasonicSensorPin = 1;
int ultrasonicSensorValue;

/**** WiFi ****/
const char* ssid = "Ikea Net";
const char* password = "hallo123hallo";
const char* mqtt_server = "172.20.10.3"; // IP deines Docker-Hosts

WiFiClient espClient;
PubSubClient client(espClient);

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
    um.setup_wifi(ssid,password);
    client.setServer(mqtt_server, 1883);
}

void loop()
{
    // InverredSensor
    infraredSensorValue = s.getInfreredSensor(infraredSensorPin);
    Serial.println(infraredSensorValue);


    // Ausführung
    if(um.delayWithoutDelay(previousMillis,500)){um.send("guten tag");}
    // action();
}
    
void action()
{
    digitalWrite(ledPin,ledState);
}