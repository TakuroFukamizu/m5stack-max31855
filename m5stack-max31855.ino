#include <Arduino.h>
#include <M5Unified.h>
#include "MAX31855.h"


void setup() {
  // M5Stack Setup
  auto cfg = M5.config();
  cfg.internal_rtc  = false;
  cfg.internal_imu  = false;
  cfg.internal_mic  = false;
  M5.begin(cfg);

  // Thermocouple setup
  max31855.begin(THERMO_COUPLE_SCK, THERMO_COUPLE_MISO, THERMO_COUPLE_MOSI,
                 THERMO_COUPLE_SLAVE);

  Serial.println("initialized");
}

void loop() {
  M5.Display.clear();
  // thermocouple error
  if (max31855.readThermocoupleTemperature() > 0) {
    Serial.println("thermocouple error");
    M5.Display.drawString("error", 0, 0);
    timerCount = 0;
    isProcessing = false;
    reflowProfile->Stop();
    return;
  }
  M5.Lcd.drawString(
      String(max31855.thermocoupleTemp, 4),
      150, 0);
  Serial.println(max31855.thermocoupleTemp);
  M5.update();
  delay(500);
}