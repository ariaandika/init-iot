#include "Arduino.h"
#include "esp_camera.h"
#include "CamAiThinker.cpp"

void camera_setup() {
    esp_err_t err = esp_camera_init(&camera_config);

    while (err != ESP_OK) {
        Serial.print("[CAMERA] setup failed: ");
        Serial.println(err);
        Serial.println("[CAMERA] retrying...");

        delay(1000);
        err = esp_camera_init(&camera_config);
    }

    Serial.println("[CAMERA] setup ok");
}

