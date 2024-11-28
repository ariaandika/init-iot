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

[source](https://docs.platformio.org/en/latest/core/quickstart.html)

