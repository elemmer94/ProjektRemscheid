class UsefullMethods
{
    // Delayschleife ohne Delay
    public: bool delayWithoutDelay(unsigned long previousMillis,const long interval)
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

    // WLAN und Moskito
    // Setup
    public: void setup_wifi(const char* ssid, const char* password) 
    {
        WiFi.begin(ssid, password);
        // Serial.println("Connect to %c",ssid);

        while(WiFi.status() != WL_CONNECTED){
            Serial.print(".");
            delay(500);
        }
        Serial.println();
    }
    // Reconnect
    public: void reconnect() {
        while(!client.connected()){
            if(client.connect("ESPClient")){
                client.subscribe("test/topic");
            }else{
                delay(5000);
            }
        }
    }
    // Send
    public: void send(const char* message)
    {
        if(!client.connected()){this->reconnect();}
        
        client.loop();
        client.publish("test/topic", message);
    }
};