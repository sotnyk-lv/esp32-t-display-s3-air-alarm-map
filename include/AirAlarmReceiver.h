#ifndef AIR_ALARM_RECEIVER_H
#define AIR_ALARM_RECEIVER_H

#include <WiFi.h>
#include <WiFiClient.h>
#include <vector>

#include "secrets.h"
// #include "AirAlarmMap.h"
#include "RegionState.h"
// #include "regions_bitmap.h"


#define HOST "tcp.alerts.com.ua"
#define PORT 1024

class AirRaidAlertApi {

public:
    AirRaidAlertApi();

    ~AirRaidAlertApi();

    void getInitialData();

    void connectApi();

    static int connectWiFi(const char* ssid, const char* password,  int maxTries = 600);

    std::vector<RegionState> handleData(String data);

    RegionState processPacket(String data);

// private:

    WiFiClient client;

};



#endif // AIR_ALARM_RECEIVER_H
