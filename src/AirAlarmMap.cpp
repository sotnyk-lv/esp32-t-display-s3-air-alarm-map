#include "AirAlarmMap.h"


AirAlarmMap::AirAlarmMap() : regions(
                              { &crimea,
                                &vinnytsia,
                                &volyn,
                                &dnipropetrovsk,
                                &donetsk,
                                &zhytomyr,
                                &zakarpattia,
                                &zaporizhzhia,
                                &frankivsk,
                                &kyiv,
                                &kirovohrad,
                                &luhansk,
                                &lviv,
                                &mykolaiv,
                                &odesa,
                                &poltava,
                                &rivne,
                                &sumy,
                                &ternopil,
                                &kharkiv,
                                &kherson,
                                &khmelnytskyi,
                                &cherkasy,
                                &chernivtsi,
                                &chernihiv}){

}

AirAlarmMap::~AirAlarmMap() {

}

void AirAlarmMap::initMap() {
    // Screen setup
    lcd.init();
    lcd.setRotation(1);
    lcd.setSwapBytes(false);
    lcd.fillScreen(TFT_BLACK);  
    // set unknown states for all region
    for (int i=0; i<25; ++i) {
        regions[i]->setUnknown();
    }
    delay(1000);
}




void AirAlarmMap::initApi() {
    apiClient.connectWiFi(WIFI_SSID, PASSWORD);
    apiClient.connectApi();
}

void AirAlarmMap::updateMap() {
    String data;
    std::vector<RegionState> regionsState;
    while (apiClient.client.available() > 0)
    {
        data += (char)apiClient.client.read();
    }
    if (data.length()) {
        regionsState = apiClient.handleData(data);
    }
    for (auto & element : regionsState) {
        if (element.region >= 25 or element.region <= 0) {
            Serial.print(" strange state: ");
            Serial.println(element.region);
            continue;
        }
        if (element.state == stateAlert) {
            regions[element.region]->raiseAlert();
            Serial.println(" raiseAlert");
        }
        else if (element.state == statePeace) {
            regions[element.region]->removeAlert();
            Serial.println(" removeAlert");
        }
        else if (element.state == stateUnknown) {
            regions[element.region]->setUnknown();
            Serial.println(" setUnknown");
        }
        else {
            Serial.println(" set error");
        }
    }
}