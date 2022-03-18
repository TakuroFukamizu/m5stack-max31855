#include <Arduino.h>
#include <M5Unified.h>
#include "MAX31855.h"

#define THERMO_COUPLE_SCK 18
#define THERMO_COUPLE_MISO 19
#define THERMO_COUPLE_MOSI 23
#define THERMO_COUPLE_SLAVE 5

void setup() {
  // M5Stack Setup
  auto cfg = M5.config();
//  cfg.internal_rtc  = false;
//  cfg.internal_imu  = false;
//  cfg.internal_mic  = false;
  M5.begin(cfg);

  // Thermocouple setup
  max31855.begin(
    THERMO_COUPLE_SCK, 
    THERMO_COUPLE_MISO, 
    THERMO_COUPLE_MOSI,
    THERMO_COUPLE_SLAVE
  );

  Serial.println("initialized");
}

void loop() {
  M5.Display.clear();
  // thermocouple error
  if (max31855.readThermocoupleTemperature() > 0) {
    // NOTE: M5Stack + M5Unified 使用時に、ここでMAX31855から受信するデータがおかしくなってしまい、誤ってエラー判定になってしまう。
    Serial.println("thermocouple error");
    M5.Display.drawString("error", 0, 0);
  } else {
    M5.Lcd.drawString(
        String(max31855.thermocoupleTemp, 4),
        150, 0);
    Serial.println(max31855.thermocoupleTemp);
  }
  M5.update();
  delay(1000);
}
