class usefullMethods
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

    public: void testung()
    {
        if(this->test2()){
            Serial.println("true");
        }else{
            Serial.println("moisnen");
        }
    }
    
    void action()
    {
        Serial.println("actions");
    }

    bool test2()
    {
        return false;
    }

};
