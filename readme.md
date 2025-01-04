# ESP32 in linux with platformio

this repo explain platformio setup and example project or device testing

## Setup platformio

install the binary and make sure follow the `99-platformio-udev.rules` setup

[source](https://docs.platformio.org/en/latest/core/installation/index.html)

## Creating project

find your board id from [here](https://docs.platformio.org/en/latest/boards/index.html#boards)

example: esp32dev, esp32cam

```bash
mkdir iot-project && cd iot-project
pio project init --board BOARD_ID --board BOARD_ID
vim src/main.cpp
```

quickstart cpp

```c
#include "Arduino.h"
#define LED_BUILTIN 13

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

- building: `pio run`
- uploading: `pio run -t upload`
- other environment: `pio run -e esp32cam`
- watch serial monitor: `pio device monitor`

[source](https://docs.platformio.org/en/latest/core/quickstart.html)

## Environment Variable

using `.env`, define build flags in platformio.ini,
then the value is available as global variable in source code

```ini
build_flags =
    -D SERVER_ADDR='"${sysenv.TCP_SERVER_ADDR}"'
    -D SERVER_PORT=${sysenv.TCP_SERVER_PORT}
```

## Dependency

searching dependency from `pio` cli

```bash
pio pkg search "WifiManager"
```

declare dependency in `platformio.ini`

```ini
lib_deps =
    tzapu/WiFiManager
```

deps will get installed on the next build, or manually using command

```bash
pio pkg install
```

