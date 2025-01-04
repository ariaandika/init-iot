#include "Arduino.h"
#include "Config.cpp"

int button_last_state = 0;
int button_press = 0;
int button_held = 0;

void button_setup() {
    Serial.print("[BUTTON] pin ");
    Serial.println(BUTTON_PIN);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void button_loop() {
    int current = !digitalRead(BUTTON_PIN);

    if (current && button_last_state) {
        button_press = 0;
        button_held = 1;

    } else if (current && !button_last_state) {
        button_last_state = 1;
        button_press = 1;
        button_held = 0;

    } else {
        button_last_state = 0;
        button_press = 0;
        button_held = 0;
    }
}

int button_is_pressed() {
    return button_press;
}

void button_debug() {
    Serial.print("[BUTTON] ");
    Serial.print("raw state: ");
    Serial.print(digitalRead(BUTTON_PIN));
    Serial.print(", pres: ");
    Serial.print(button_press);
    Serial.print(", held: ");
    Serial.print(button_held);
    Serial.println();
}

