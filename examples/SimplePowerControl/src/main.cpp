#include <M5Stack.h>
#include <PowerControl.h>

PowerControl power = PowerControl(&M5.Lcd);

void setup() {
    M5.begin();               // Initialise the display
    M5.Power.begin();
}

void loop() {

    // Draw battery on upper left corner
    power.drawAt(0, 0); 


    M5.update(); 
    if (M5.BtnA.pressedFor(3000)) {
        M5.Power.powerOFF();
    }
}