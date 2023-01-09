#ifndef REGION_H
#define REGION_H

#include <TFT_eSPI.h>
#include <cstdint>
#include <algorithm>
#include <iterator>


class Region {

public:
    // TODO check if correct and fix
    Region(TFT_eSPI *lcd, 
        const uint16_t coordinates_x, const uint16_t coordinates_y, 
        const uint16_t size_x, const uint16_t size_y,
        const uint16_t *bitmap);

    // TODO check if correct and fix
    ~Region();

    // TODO does I need it?
    void setCoordinates(uint16_t x, uint16_t y);

    bool isAlert();

    void raiseAlert();
    void removeAlert();

    // someTimeFormat lastAlert(); 

private:

    uint16_t coordinates_x;
    uint16_t coordinates_y;
    uint16_t size_x;
    uint16_t size_y;

    TFT_eSPI *lcd;
    TFT_eSprite *sprite;

    // char name[15];

    const uint16_t *bitmap;

    bool alert = false;
};

#endif // REGION_H