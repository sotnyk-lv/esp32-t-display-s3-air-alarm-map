#ifndef REGION_H
#define REGION_H

#include <TFT_eSPI.h>
#include <cstdint>
#include <algorithm>
#include <iterator>

#include "SingleColorBitmap.h"

class Region : protected SingleColorBitmap{

public:
    using SingleColorBitmap::SingleColorBitmap;
    
    // B(int x) : A(x) { }

    int isAlert();

    void setUnknown();
    void raiseAlert();
    void removeAlert();


    // someTimeFormat lastAlert(); 

private:

    int state = -1;
};

#endif // REGION_H