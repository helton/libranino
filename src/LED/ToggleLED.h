#ifndef TOGGLELED_H
#define TOGGLELED_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/AsyncComponent.h"
#include "LED.h"

class ToggleLED : public LED, public AsyncComponent {
public:
    ToggleLED(uint8_t pin) : LED(pin) {
        _previousTime = 0;
    }
    void begin(unsigned long interval) {
        _interval = interval;
    }
    void update() override {
        unsigned long current = millis();
        if (current - _previousTime >= _interval) {
            _previousTime = current;
            toggle();
        }
    }
private:
    unsigned long _previousTime;
    unsigned long _interval;
};

#endif //TOGGLELED_H
