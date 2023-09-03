#include "AirAlarmReceiver.h"
#include "AirAlarmMap.h"


AirRaidAlertApi::AirRaidAlertApi() {
}

AirRaidAlertApi::~AirRaidAlertApi() {
}

void AirRaidAlertApi::connectApi() {
    if (WiFi.status() != WL_CONNECTED && !AirRaidAlertApi::connectWiFi(WIFI_SSID, PASSWORD)) {
        Serial.println("WiFi connection is not astablished");
        return;
    }
    Serial.print("Connecting to Air Raid Alert API...");
    int maxTries = 60;
    int i = 0;
    for (; i < maxTries; ++i) {
        if (client.connect(HOST, PORT)) {
            break;
        }
        Serial.println(" Failed.");
        delay(1000);
    }
    if (i >= maxTries) {
        Serial.println("\nAPI connection is not astablished");
        return;
    }

    Serial.println(" Connected!");
    client.write(API_KEY);
}

int AirRaidAlertApi::connectWiFi(const char* ssid, const char* password, int maxTries) {
    // WiFi setup
    WiFi.begin(WIFI_SSID, PASSWORD);
    Serial.println("\nConnecting to the WiFi network");
    int i = 0;
    for (; i < maxTries; ++i) {
        if (WiFi.status() == WL_CONNECTED) {
            break;
        }
        Serial.print(".");
        delay(100);
    }
    if (i >= maxTries) {
        Serial.println("\nWiFi connection is not astablished");
        return 1;
    }

    // WiFi connection established
    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
    return 0;

}


void AirRaidAlertApi::getInitialData() {
    // static String buffer;
    // buffer += data;
    // std::array<RegionState> regionStates(25);
    // while (1) {
    //     int border = buffer.indexOf("\n");
    //     if (border == -1) {
    //         break;
    //     }
    //     regionStates.push_back(processPacket(buffer.substring(0, border)));
    //     buffer = buffer.substring(border + 1);
    // }
    // return regionStates;    
}

std::vector<RegionState> AirRaidAlertApi::handleData(String data) {
    static String buffer;
    buffer += data;
    std::vector<RegionState> regionStates;
    while (1) {
        int border = buffer.indexOf("\n");
        if (border == -1) {
            break;
        }
        regionStates.push_back(processPacket(buffer.substring(0, border)));
        buffer = buffer.substring(border + 1);
    }
    return regionStates;
}

RegionState AirRaidAlertApi::processPacket(String data) {
    Serial.print("Got packet: ");
    Serial.println(data);

    if (data == "a:wrong_api_key") {
      Serial.println("Please specify your API key!");
      delay(5000);
      return RegionState(unknownRegion, stateError);
    }
    if (data[0] == 's') {
      int currentRegion = data.substring(2).toInt();
      int currentState = data.substring(data.indexOf("=")+1, data.indexOf("=")+2).toInt();

      if (currentRegion > 24 || currentRegion < 1) {
        // region with number 25 is Kyiv city. We ignore it for now.
        // other regions are not supported.
        // Krimea is region 0, it's status is not supported by the api.
        return RegionState(unknownRegion, stateUnknown);
      }

      if (currentState) {
        // regions[currentRegion]->raiseAlert();
        return RegionState(currentRegion, stateAlert);
        Serial.println(" raiseAlert");
      }
      else {
        // regions[currentRegion]->removeAlert();
        return RegionState(currentRegion, statePeace);
        Serial.println(" removeAlert");
      }
      Serial.println("\n");
      return RegionState(currentRegion, stateError);

    }
    return RegionState(unknownRegion, stateError);

}

