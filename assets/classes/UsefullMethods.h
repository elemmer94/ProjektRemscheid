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
};
