#include <TFT_eSPI.h>

#include "map_w.h"

TFT_eSPI lcd = TFT_eSPI();

void setup(void)
{    
    lcd.init();
    lcd.setRotation(1);
    lcd.setSwapBytes(true);
    lcd.fillScreen(TFT_BLACK);

    lcd.pushImage(0, 0, 254, 170, map_w);
}

void loop()
{
  
}

  
