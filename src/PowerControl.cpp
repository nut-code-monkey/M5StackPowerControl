#include "PowerControl.h"

#include <M5Stack.h>
#include <Arduino.h>

PowerControl::PowerControl(M5Display *display) {
    sprite = new TFT_eSprite(display);

    sprite->setColorDepth(8);
    sprite->createSprite(16, 10);
    // sprite->fillSprite(TFT_TRANSPARENT);
    color = WHITE;
    background = BLACK;
}

PowerControl::~PowerControl() {
    delete sprite;
}

uint16_t PowerControl::width() const {
    return sprite->width();
}

uint16_t PowerControl::height() const {
    return sprite->height();
}

void PowerControl::setColor(uint16_t color) {
    this->color = color;
}

void PowerControl::setBackground(uint16_t color) {
    this->background = color;
}

void PowerControl::drawAt(uint16_t x, uint16_t y) {
    sprite->fillSprite(background);
    // Draw frame

    
    bool drawFrame = true;

    const auto line_width = 3;

    if (drawFrame) {
        sprite->drawLine(0, 1, 0, 7, color);
        sprite->drawLine(1, 0, 13, 0, color);
        sprite->drawLine(1, 9, 13, 9, color);
        sprite->drawLine(14, 1, 14, 8, color);
        sprite->drawLine(15, 3, 15, 6, color);
    };

    auto lines = (M5.Power.getBatteryLevel() / 25) * line_width;
    for (int8_t i = 0; i < lines; i+=line_width) {
        int n = i + 2;
        sprite->drawLine(n,   2, n,   7, color);
        sprite->drawLine(n+1, 2, n+1, 7, color);
    }

    sprite->pushSprite(x, y);
}