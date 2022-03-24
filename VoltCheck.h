#include <Arduino.h>
#ifndef VoltCheck_H
#define VoltCheck_H

class VoltCheck {
 public:
  int8_t pin;
  static constexpr float a = 0.8f;
  float rc = 0.0f;
  int volt;

public:
  int8_t begin(int8_t pin);
  void readMilliVolt();
};
extern VoltCheck voltCheck;
#endif
