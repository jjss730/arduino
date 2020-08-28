
#ifndef PIRSensor_h
#define PIRSensor_h

#include <Arduino.h>

class PIRSensor
{
  public:
    PIRSensor(int pin);

    void begin();
    bool status();

  private:
    int _pin;
    bool _status;
};

#endif
