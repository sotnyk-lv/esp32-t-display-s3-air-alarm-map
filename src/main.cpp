#include <Arduino.h>
#include <TFT_eSPI.h>

#include <WiFi.h>
#include <WiFiClient.h>

WiFiClient client;

#include "secrets.h"

#include "regions_bitmap.h"
#include "Region.h"

TFT_eSPI lcd = TFT_eSPI();
int i = 0;

void processPacket(String data) {
    Serial.print("Got packet: ");
    Serial.println(data);
    if (data == "a:wrong_api_key") {
      Serial.println("Please specify your API key!");
      delay(5000);
    }
    if (data[0] == 's') {
      int currentRegion = data.substring(2).toInt();
      Serial.print("currentRegion: ");
      Serial.print(currentRegion);
      Serial.print(data.substring(data.indexOf("=")+1, data.indexOf("=")+2));
      Serial.print(" ");
      int currentState = data.substring(data.indexOf("=")+1, data.indexOf("=")+2).toInt();
      Serial.print(" currentState: ");
      Serial.print(currentState);

      if (currentRegion > 24 || currentRegion < 1) {
        Serial.println(" brrr");
        return ;
      }

      if (currentState) {
        regions[currentRegion]->raiseAlert();
        Serial.println(" raiseAlert");
      }
      else {
        regions[currentRegion]->removeAlert();
        Serial.println(" removeAlert");
      }

    }
    Serial.println("\n");
}

void handleData(String data) {
    static String buffer;
    buffer += data;
    while (1) {
        int border = buffer.indexOf("\n");
        if (border == -1) {
            break;
        }
        processPacket(buffer.substring(0, border));
        buffer = buffer.substring(border + 1);
    }
}

void setup() {
  lcd.init();
  lcd.setRotation(1);
  lcd.setSwapBytes(true);
  lcd.fillScreen(TFT_BLACK);

  delay(5000);
  
  
  Serial.begin(9600);
  Serial.println("start");

  WiFi.begin(SSID, PASSWORD);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());


    Serial.print("Connecting to Air Raid Alert API...");
    while (!client.connect(HOST, PORT))
    {
        Serial.println(" Failed.");
        delay(1000);
    }
    Serial.println(" Connected!");
    client.write(API_KEY);

    for (int i=0; i<25; ++i) {
      regions[i]->setUnknown();
    }
}

void loop() {
  i++;
  Serial.print("loop ");
  Serial.println(i);
  
  String data;
  while (client.available() > 0)
  {
      data += (char)client.read();
  }
  if (data.length()) {
    handleData(data);
  }

  delay(10000);

}