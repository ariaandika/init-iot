# ESP32 in linux with platformio

## Setup platformio

install the binary and make sure follow the `99-platformio-udev.rules` setup

[source](https://docs.platformio.org/en/latest/core/installation/index.html)

## Creating project

find your board id from [here](https://docs.platformio.org/en/latest/boards/index.html#boards)

```bash
mkdir iot-project && cd iot-project
pio project init --board BOARD_ID
vim src/main.cpp
```

quickstart cpp

```c
#include "Arduino.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

this will make the built in led blink

- building: `pio run`
- uploading: `pio run --target upload`
- watch serial monitor: `pio device monitor`

[source](https://docs.platformio.org/en/latest/core/quickstart.html)

## Environment Variable

using environment variables, define build flags in platformio.ini,
then the value is available as global variable in source code

```ini
build_flags =
    -D WIFI_SSID='"${sysenv.WIFI_SSID}"'
    -D WIFI_PASS='"${sysenv.WIFI_PASS}"'
    -D TCP_SERVER_ADDR='"${sysenv.TCP_SERVER_ADDR}"'
    -D TCP_SERVER_PORT=${sysenv.TCP_SERVER_PORT}
```

for this project example following environment variables is required:

- `WIFI_SSID`
- `WIFI_PASS`
- `TCP_SERVER_ADDR`
- `TCP_SERVER_PORT`


