#ifndef SINGLECOLORBITMAP_H
#define SINGLECOLORBITMAP_H

#include <TFT_eSPI.h>
#include <cstdint>
#include <algorithm>
#include <iterator>

class SingleColorBitmap {

public:
    // TODO check if correct and fix
    SingleColorBitmap(TFT_eSPI *lcd, 
        const uint16_t coordinates_x, const uint16_t coordinates_y, 
        const uint16_t size_x, const uint16_t size_y,
        const uint16_t *bitmap);

    // TODO check if correct and fix
    ~SingleColorBitmap();

    void setColor(uint16_t color);

    // someTimeFormat lastAlert(); 

private:

    uint16_t coordinates_x;
    uint16_t coordinates_y;
    uint16_t size_x;
    uint16_t size_y;

    TFT_eSPI *lcd;
    TFT_eSprite *sprite;

    const uint16_t *bitmap;

};

#endif // SINGLECOLORBITMAP_H
