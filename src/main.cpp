#include <Arduino.h>
#include <TFT_eSPI.h>

#include "cherkasy.h"

TFT_eSPI lcd = TFT_eSPI();
extern TFT_eSprite cherkasySprite;

void setup() {
  lcd.init();
  lcd.setRotation(1);
  lcd.setSwapBytes(true);
  lcd.fillScreen(TFT_BLACK);

  setUpCherkasy();

  // lcd.pushImage(0, 0, 254, 170, map_w);
}

void loop() {
  // put your main code here, to run repeatedly:
}