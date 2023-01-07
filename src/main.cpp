#include <Arduino.h>
#include <TFT_eSPI.h>

#include "cherkasy.h"
#include "Region.h"

TFT_eSPI lcd = TFT_eSPI();
extern TFT_eSprite cherkasySprite;
int i = 0;

void setup() {
  lcd.init();
  lcd.setRotation(1);
  lcd.setSwapBytes(true);
  lcd.fillScreen(TFT_BLACK);

  Region cherkasy(&lcd, 60,60,44,37, cherkasyBitmap);

  // setUpCherkasy();
  // cherkasySprite.setColorDepth(1);
  
  Serial.begin(9600);
  Serial.println("start");
  // lcd.pushImage(0, 0, 254, 170, map_w);
}

void loop() {
  i++;
  Serial.print("loop ");
  Serial.println(i);

  // cherkasySprite.pushSprite(0,0, TFT_BLACK);

  delay(500);
}