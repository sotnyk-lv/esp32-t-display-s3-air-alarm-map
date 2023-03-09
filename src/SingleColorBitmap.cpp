#include "SingleColorBitmap.h"

SingleColorBitmap::SingleColorBitmap(TFT_eSPI *lcd, 
        const uint16_t coordinates_x, const uint16_t coordinates_y, 
        const uint16_t size_x, const uint16_t size_y, 
        const uint16_t *flash_bitmap) 
        : lcd(lcd),
        coordinates_x(coordinates_x), coordinates_y(coordinates_y),
        size_x(size_x), size_y(size_y)
{   

    sprite = new TFT_eSprite(lcd);
    bitmap = flash_bitmap;
    // sprite->createSprite(size_x, size_y);
    // sprite->setSwapBytes(true);
    // sprite->pushImage(0, 0, size_x, size_y, bitmap);
    
    // sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);

    // sprite->deleteSprite();
}

SingleColorBitmap::~SingleColorBitmap() {
    delete sprite;
}

void SingleColorBitmap::setColor(uint16_t color) {
    uint16_t *color_bitmap = new uint16_t [size_x*size_y];

    for (uint16_t i = 0; i < size_x*size_y; i++) {
        if (bitmap[i] == TFT_WHITE) {
            color_bitmap[i] = color;
        }
        else {
            color_bitmap[i] = TFT_BLACK;
        }
    }
    sprite->createSprite(size_x, size_y);
    sprite->setSwapBytes(true);
    sprite->pushImage(0, 0, size_x, size_y, color_bitmap);
    
    sprite->pushSprite(coordinates_x, coordinates_y, TFT_BLACK);

    sprite->deleteSprite();

    delete [] color_bitmap;
}
