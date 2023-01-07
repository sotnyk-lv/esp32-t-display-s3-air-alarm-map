#include "Region.h"

Region::Region(TFT_eSPI *lcd, 
        const uint16_t coordinates_x, const uint16_t coordinates_y, 
        const uint8_t size_x, const uint8_t size_y, 
        const unsigned short *bitmap) 
        : lcd(lcd), alert(false),
        coordinates(coordinates_x, coordinates_y),
        size(size_x, size_y) 
{
    sprite = new TFT_eSprite(lcd);

    sprite->createSprite(size_x, size_y);
    sprite->setSwapBytes(true);
    sprite->pushImage(0, 0, size_x, size_y, bitmap);
    
    sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);
}

Region::~Region() {
    sprite->deleteSprite();
    delete sprite;
}

void Region::setCoordinates(uint16_t x, uint16_t y) {
    coordinates = Pair<uint16_t>(x,y);
    // TODO
}

bool Region::isAlert() {
    return alert;
}

void Region::raiseAlert() {
    alert = true;
    // TODO
}

void Region::removeAlert() {
    alert = false;
    // TODO
}
