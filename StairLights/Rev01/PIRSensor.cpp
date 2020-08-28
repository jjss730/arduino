
#include "PIRSensor.h"



PIRSensor::PIRSensor(int pin)
{
  _pin = pin;
}

void PIRSensor::begin()
{
  pinMode(_pin,INPUT);
}

bool PIRSensor::status()
{
  return digitalRead(_pin);
}
