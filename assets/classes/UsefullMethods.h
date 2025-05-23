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
        Serial.print("Connect to WiFi: ");
        Serial.println(ssid);

        while(WiFi.status() != WL_CONNECTED){
            Serial.print(".");
            delay(500);
        }
        Serial.println();
        Serial.println("Connected");
    }
    // Reconnect
    public: void reconnect(PubSubClient client) {
        while(!client.connected()){
            if(client.connect("ESPClient")){
                client.subscribe("test/topic");
            }else{
                Serial.println("Nicht Verbunden");
                delay(5000);
            }
        }
    }
    // Send
    public: void send(const char* message, PubSubClient client)
    {
        if(!client.connected()){this->reconnect(client);}
        
        client.loop();
        client.publish("test/topic", message);
    }
};