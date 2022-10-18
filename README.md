## M5StackPowerControl for M5Stack
PowerControl view sprite that show battery charging state. 

### Usage via PlatformIO Package Manager:

Just add dependency to you `platformio.ini` file:
```
lib_deps = nut-code-monkey/M5StackPowerControl
```
in your code:
```
#include <M5Stack.h>
#include <PowerControl.h>

PowerControl power = PowerControl(&M5.Lcd);

void setup() {
   // Initialise m5 stack:
    M5.begin();       
    M5.Power.begin();

    // Optional: set colors:
    power.color = TFT_WHITE;
    power.charging = TFT_GREEN;
    power.background = TFT_TRANSPARENT;
}

void loop() {
    // Draw battery on upper left corner
    power.drawAt(0, 0); 
}
```
