#include <M5Stack.h>
#include <PowerControl.h>

PowerControl power = PowerControl(&M5.Lcd);

void setup() {
    // Initialise m5stack:
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

    M5.update(); 
    if (M5.BtnA.pressedFor(3000)) {
        M5.Power.powerOFF();
    }
}