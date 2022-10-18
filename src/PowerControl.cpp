#include "PowerControl.h"

PowerControl::PowerControl(M5Display *display)
: sprite(TFT_eSprite(display))
 {
    sprite.setColorDepth(8);
    sprite.createSprite(16, 10);
}

PowerControl::~PowerControl() {
}

int16_t PowerControl::width() {
    return sprite.width();
}

int16_t PowerControl::height() {
    return sprite.height();
}

void PowerControl::drawAt(int16_t x, int16_t y) {
    auto time = millis() % 1000;
    bool on = time > 500;
    if (on == isOn) {
        return;
    }
    isOn = on;

    bool isChargeFull = M5.Power.isChargeFull();
    bool isCharging = M5.Power.isCharging();

    uint16_t drawColor = isCharging ? charging : color;
    if (isChargeFull) {
        drawColor = color;
    }

    sprite.fillSprite(background);
    
    // Draw frame
    sprite.drawFastVLine(0, 1, 7, drawColor);
    sprite.drawFastHLine(1, 0, 12, drawColor);
    sprite.drawFastHLine(1, 9, 12, drawColor);
    sprite.drawFastVLine(14, 1, 7, drawColor);
    if (isCharging) {
        if (isOn) {
            sprite.drawFastVLine(15, 3, 3, drawColor);
        }
    } else {
        sprite.drawFastVLine(15, 3, 3, drawColor);
    }
    
    const int level_bars = M5.Power.getBatteryLevel() / 25;
    const int display_bars = min(4, level_bars + ((isCharging && isOn) ? 1:0));
    
    for (int i = 0; i < display_bars; ++i) {
        int n = i*3 + 2;
        sprite.drawFastVLine(n,   2, 5, drawColor);
        sprite.drawFastVLine(n+1, 2, 5, drawColor);
    }

    sprite.pushSprite(x, y);
}