#pragma once
class SensorInterface {
public:
    virtual void begin() = 0;
    virtual void loop() = 0;
    virtual ~SensorInterface() = default;
};