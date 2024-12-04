#include "Arduino.h"
#include "WiFi.h"

WiFiClient TCP_client;

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup() {
    Serial.begin(9600);

    // Connect to Wifi.
    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.println("Connecting...");

    while (WiFi.status() != WL_CONNECTED) {
      if (WiFi.status() == WL_CONNECT_FAILED) {
        Serial.println("Failed to connect to WIFI");
      }
      delay(5000);
    }

    Serial.println("WiFi connected, IP: ");
    Serial.println(WiFi.localIP());

    // connect to TCP server
    if (TCP_client.connect(TCP_SERVER_ADDR, TCP_SERVER_PORT)) {
      Serial.println("Connected to TCP server");
      TCP_client.write("Hello!");  // send to TCP Server
      TCP_client.flush();
    } else {
      Serial.println("Failed to connect to TCP server");
    }
}

void loop() {
  delay(5000);
  Serial.println("Oof");
}
