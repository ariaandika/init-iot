#include "Arduino.h"
#include "Config.cpp"
#include "ESP32Servo.cpp"

int servo_degree = 0;

Servo servo;

void servo_setup() {
    Serial.print("[SERVO] pin ");
    Serial.println(SERVO_PIN);

    servo.attach(SERVO_PIN);
    servo.write(servo_degree);
}

int servo_get() {
    return servo_degree;
}

void servo_set(int deg) {
    servo_degree = deg;
    servo.write(servo_degree);
}

void servo_debug() {
    int deg = servo_get();
    servo_set(deg == 90 ? 0 : deg + 45);

    Serial.print("[SERVO] ");
    Serial.println(servo_get());
}

