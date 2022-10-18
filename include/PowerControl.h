#ifndef __POWER_CONTROL_H__
#define __POWER_CONTROL_H__

#include <cstdint>
#include <M5Stack.h>

class PowerControl {
private:
    TFT_eSprite sprite;
    bool isOn = false;
public:
    PowerControl(M5Display *);
    ~PowerControl();
    uint16_t color = TFT_WHITE;
    uint16_t charging = TFT_GREEN;
    uint16_t background = TFT_TRANSPARENT;
    int16_t width();
    int16_t height();

    void drawAt(int16_t x, int16_t y);
};

#endif //__POWER_CONTROL_H__