#ifndef AIRALARMRECEIVER_H
#define AIRALARMRECEIVER_H

#include <WiFi.h>
#include <WiFiClient.h>

#include "secrets.h"

class WiFiConnection {

public:
    WiFiConnection();

    ~WiFiConnection();

    void connectWiFi(const char* ssid, const char* password);

    void connectAPI();

private:

    WiFiClient client;

};

#endif // AIRALARMRECEIVER_H
