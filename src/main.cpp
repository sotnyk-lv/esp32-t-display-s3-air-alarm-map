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

  // // create full map
  // TFT_eSprite ukraineSprite(&lcd);
  // ukraineSprite.createSprite(254, 170);
  // ukraineSprite.setSwapBytes(true);
  // ukraineSprite.pushImage(0, 0, 254, 170, ukraineBitmap);
  // ukraineSprite.pushSprite(0, 0, TFT_BLACK);
  // ukraineSprite.deleteSprite();

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
  chernivtsi.raiseAlert();
  crimea.raiseAlert();
  dnipropetrovsk.raiseAlert();
  donetsk.raiseAlert();
  frankivsk.raiseAlert();
  kharkiv.raiseAlert();
  kherson.raiseAlert();
  khmel.raiseAlert();
  kirovohrad.raiseAlert();
  kyiv.raiseAlert();
  luhansk.raiseAlert();
  lviv.raiseAlert();
  mykolaiv.raiseAlert();
  odesa.raiseAlert();
  poltava.raiseAlert();
  rivne.raiseAlert();
  symu.raiseAlert();
  ternopil.raiseAlert();
  vinnytsia.raiseAlert();
  volyn.raiseAlert();
  zakarpattia.raiseAlert();
  zaporizhia.raiseAlert();
  zhytomyr.raiseAlert();

  delay(1000);
  cherkasy.removeAlert();
  chernihiv.removeAlert();
  chernivtsi.removeAlert();
  crimea.removeAlert();
  dnipropetrovsk.removeAlert();
  donetsk.removeAlert();
  frankivsk.removeAlert();
  kharkiv.removeAlert();
  kherson.removeAlert();
  khmel.removeAlert();
  kirovohrad.removeAlert();
  kyiv.removeAlert();
  luhansk.removeAlert();
  lviv.removeAlert();
  mykolaiv.removeAlert();
  odesa.removeAlert();
  poltava.removeAlert();
  rivne.removeAlert();
  symu.removeAlert();
  ternopil.removeAlert();
  vinnytsia.removeAlert();
  volyn.removeAlert();
  zakarpattia.removeAlert();
  zaporizhia.removeAlert();
  zhytomyr.removeAlert();

}