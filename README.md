# MQx-Library
This library are used to obtain PPM (parts per million) using the analog input of the MQx gas sensor.

## Pre requisites
The following involves the basic connection of MQx and Arduino or ESP board and the use of this library.
1. Connect the VCC and GND pins of the MQx sensor to power pin in your board and GND pin respectively.
2. Wire the A0 (analog pin) of MQx sensor to any analog pin on your board.
3. Download Arduino Software (if you haven't).
4. Clone or download this files and place them under \Program Files\Arduino\libraries\MQx folder for including them in the code.

## Code


1. Include the header file to the source code.
```cpp
#include "MQ2.h" // or "MQ7.h"
```

2. Initialize the sensor object

```cpp
/*
param[1] : Analog pin number
param[2] : Sensor VCC value
param[3] : Sensor VCC range
*/
MQ2 mq2(35, 3.3, 4095.0); 
```

3. To find the ppm
```cpp
float ppm = mq2.getPPM();
```

4. Complete Code
```cpp
#include <Arduino.h>
#include "MQ2.h"

int pinMQ2 = 35;
float voltInput = 3.3;
float voltRange = 4095.0;

MQ2 mq2(pinMQ2, voltInput, voltRange);

void setup() {
  Serial.begin(115200);
  pinMode(pinMQ2, INPUT);
}

void loop() {
  float mq2Ppm = mq2.getPPM();
  Serial.println(mq2Ppm);
}

```

This library can be used on any Arduino or ESP boards. Just vary the param[2] and param[3] based on the VCC.