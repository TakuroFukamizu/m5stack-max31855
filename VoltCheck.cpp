#include <Arduino.h>
#include "VoltCheck.h"

int8_t VoltCheck::begin(int8_t pin) {
  analogSetAttenuation(ADC_6db);  //ATT -6dB
  pinMode(pin, ANALOG);

  voltCheck.pin = pin;
  return 0;
}

void VoltCheck::readMilliVolt() {
  int volt = analogReadMilliVolts(voltCheck.pin);
  volt = volt * 2; // 分圧抵抗で下げた分
  voltCheck.volt = volt;
  voltCheck.rc = voltCheck.a * voltCheck.rc + (1-voltCheck.a) * (float)volt;
}

VoltCheck voltCheck;
