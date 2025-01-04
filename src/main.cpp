// if this not included manually, WiFiManager library choked, even if WiFiManager not used
#include "WiFi.h"
#include "Update.h"
#include "WebServer.h"
#include "DNSServer.h"

#include "Arduino.h"
#include "ButtonIo.cpp"
#include "ServoIo.cpp"

void setup() {
    // button_setup();
    // servo_setup();
}

void loop() {
    // button_loop();
    // button_debug();
    // servo_debug();

    delay(500);
}

