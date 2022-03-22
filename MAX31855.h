#include <Arduino.h>
#include <SPI.h>
#ifndef MAX31855_H
#define MAX31855_H

class MAX31855 {
 public:
  int8_t slave;
  float thermocoupleTemp, internalTemp;
  SPISettings spiConfig;

 public:
  int8_t begin(int8_t sck, int8_t miso, int8_t mosi, int8_t slave);
  int8_t readThermocoupleTemperature();
};
extern MAX31855 max31855;
#endif
