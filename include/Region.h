#include <TFT_eSPI.h>
#include <cstdint>

template <class T>
struct Pair {
    T x;
    T y;

    Pair(T x, T y) {
        x = x;
        y = y;
    }
};

class Region {

public:
    // TODO check if correct and fix
    Region(TFT_eSPI *lcd, 
        uint16_t coordinates_x, uint16_t coordinates_y, 
        uint8_t size_x, uint8_t size_y,
        const unsigned short *bitmap);

    // TODO check if correct and fix
    ~Region();

    // TODO does I need it?
    void setCoordinates(uint16_t x, uint16_t y);

    bool isAlert();

    // TODO
    void raiseAlert();
    // TODO
    void removeAlert();

    // someTimeFormat lastAlert(); 

private:
    TFT_eSPI *lcd;
    TFT_eSprite *sprite;

    char name[15];
    bool alert;

    Pair<uint16_t> coordinates;
    Pair<uint8_t> size;
};