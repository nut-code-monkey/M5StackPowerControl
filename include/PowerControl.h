#ifndef __POWER_CONTROL_H__
#define __POWER_CONTROL_H__

#include <cstdint>

class M5Display;
class TFT_eSprite;

class PowerControl {
private:
    TFT_eSprite *sprite;
public:
    PowerControl(M5Display *);
    ~PowerControl();

    uint16_t color;
    uint16_t background;

    void setColor(uint16_t);
    void setBackground(uint16_t);
    uint16_t width() const;
    uint16_t height() const;

    void drawAt(uint16_t x, uint16_t y);
};

#endif //__POWER_CONTROL_H__