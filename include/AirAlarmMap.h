#ifndef AIR_ALARM_MAP_H
#define AIR_ALARM_MAP_H

#include <TFT_eSPI.h>
#include <vector>

#include "regions_bitmap.h"
#include "secrets.h"
#include "AirAlarmReceiver.h"
#include "Region.h"
#include "RegionState.h"

extern TFT_eSPI lcd;

class AirAlarmMap {

public:
    AirAlarmMap();

    ~AirAlarmMap();

    void initMap();

    void initApi();

    void updateMap();

private:

    AirRaidAlertApi apiClient;
    std::array<Region*, 25> regions;
    
};

#endif // AIR_ALARM_MAP_H
