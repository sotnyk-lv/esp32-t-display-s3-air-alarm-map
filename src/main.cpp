#include <Arduino.h>
#include <TFT_eSPI.h>

#include "regions_bitmap.h"
#include "Region.h"

TFT_eSPI lcd = TFT_eSPI();
int i = 0;

void setup() {
  lcd.init();
  lcd.setRotation(1);
  lcd.setSwapBytes(true);
  lcd.fillScreen(TFT_BLACK);

  // create full map
  TFT_eSprite ukraineSprite(&lcd);
  ukraineSprite.createSprite(254, 170);
  ukraineSprite.setSwapBytes(true);
  ukraineSprite.pushImage(0, 0, 254, 170, ukraineBitmap);
  ukraineSprite.pushSprite(0, 0, TFT_BLACK);
  ukraineSprite.deleteSprite();

  delay(1000);
  
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  i++;
  Serial.print("loop ");
  Serial.println(i);

  delay(1000);
  cherkasy.raiseAlert();
  chernihiv.raiseAlert();
  delay(1000);
  cherkasy.removeAlert();
  chernihiv.removeAlert();

  
}