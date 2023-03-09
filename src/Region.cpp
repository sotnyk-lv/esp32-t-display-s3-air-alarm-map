#include "Region.h"

int Region::isAlert() {
    return state;
}

void Region::setUnknown() {
    state = -1;
    this->setColor(TFT_DARKGREY);
}

void Region::raiseAlert() {
    state = 1;
    this->setColor(TFT_RED);
}

void Region::removeAlert() {
    state = 0;
    this->setColor(TFT_WHITE);
}
