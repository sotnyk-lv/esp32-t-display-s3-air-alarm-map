#include <Arduino.h>
#include <TFT_eSPI.h>

#include <WiFi.h>
#include <WiFiClient.h>

WiFiClient client;

#include "secrets.h"

#include "Region.h"
#include "AirAlarmReceiver.h"
#include "AirAlarmMap.h"

// main display
TFT_eSPI lcd = TFT_eSPI();
AirAlarmMap mapWorker{};
int i = 0;


void setup() {

    // Set to use the battery 
    pinMode(15, OUTPUT);
    digitalWrite(15, HIGH);

    // // Screen setup
    // lcd.init();
    // lcd.setRotation(1);
    // lcd.setSwapBytes(true);
    // lcd.fillScreen(TFT_BLACK);  

    // Serial setup
    Serial.begin(9600);
    Serial.println("start");

    mapWorker.initApi();


    Serial.print("Initialization of the regions");
    mapWorker.initMap();

    // String data;
    // while (client.available() > 0)
    // {
    //     data += (char)client.read();
    // }
    // if (data.length()) {
    //   handleData(data);
    // }
      
}

void loop() {
    i++;
    Serial.print("loop ");
    Serial.println(i);

    mapWorker.updateMap();
    
    

    delay(10000);

}