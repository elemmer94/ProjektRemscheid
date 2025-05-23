class Sensors
{
    /***** ESP1 *****/
    // Infrared Obstacle Aviodance Sensor
    public: bool getInfreredSensor(const int sensorPin)
    {
        const int ledPin =  13;
        int sensorState = false;   
        // read the state of the sensor value:
        sensorState = digitalRead(sensorPin);
        return !sensorState;
    }
    

    // SR01 Ultrasonic Sensor


    // PixyCam2


    /***** ESP2 *****/
    // PIR Motion Sensor
    public: bool motionSensor(byte sensorPin)
    {
        byte indicator = 13;
        byte state = digitalRead(sensorPin);
        digitalWrite(indicator,state);
        if(state == 1)Serial.println("Somebody is in this area!");
        else if(state == 0)Serial.println("No one!");
        delay(500);
    }

    // Analog Temperature Sensor


    /***** ESP3 *****/


    // Flame Sensor


    // Analog Gas Sensor


    // 18B20 Temperature Sensor


    /***** ESP4 *****/
    // DHT11 Temperature and Humidity Sensor


    // Vapor Sensor


    /***** RASPI *****/
    // Digital Buzzer


    // DS3231 Clock Module
};
