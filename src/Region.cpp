#include "Region.h"

Region::Region(TFT_eSPI *lcd, 
        const uint16_t coordinates_x, const uint16_t coordinates_y, 
        const uint16_t size_x, const uint16_t size_y, 
        const uint16_t *flash_bitmap) 
        : lcd(lcd), alert(false),
        coordinates_x(coordinates_x), coordinates_y(coordinates_y),
        size_x(size_x), size_y(size_y)
{   

    sprite = new TFT_eSprite(lcd);
    bitmap = flash_bitmap;
    sprite->createSprite(size_x, size_y);
    sprite->setSwapBytes(true);
    sprite->pushImage(0, 0, size_x, size_y, bitmap);
    
    sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);

    sprite->deleteSprite();
}

Region::~Region() {
    delete sprite;
}

void Region::setCoordinates(uint16_t x, uint16_t y) {
    // TODO
}

bool Region::isAlert() {
    return alert;
}

void Region::raiseAlert() {
    alert = true;

    uint16_t *red_bitmap = new uint16_t [size_x*size_y];

    for (uint16_t i = 0; i < size_x*size_y; i++) {
        if (bitmap[i] == TFT_WHITE) {
            red_bitmap[i] = TFT_RED;
        }
        else {
            red_bitmap[i] = TFT_BLACK;
        }
    }
    sprite->createSprite(size_x, size_y);
    sprite->setSwapBytes(true);
    sprite->pushImage(0, 0, size_x, size_y, red_bitmap);
    
    sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);

    sprite->deleteSprite();

    delete [] red_bitmap;
}

void Region::removeAlert() {
    alert = false;

    sprite->createSprite(size_x, size_y);
    sprite->setSwapBytes(true);
    sprite->pushImage(0, 0, size_x, size_y, bitmap);
    
    sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);

    sprite->deleteSprite();
}
