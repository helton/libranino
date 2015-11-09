#ifndef ANALOGCOMPONENT_H
#define ANALOGCOMPONENT_H

#include <Arduino.h>
#include <inttypes.h>
#include "Component.h"

class AnalogComponent : public Component {
public:
    AnalogComponent(uint8_t pin) : Component(pin) { }
    int getAnalogValue() {
    	return analogRead(_pin);
    }
    void setAnalogValue(int value) {
    	analogWrite(_pin, value);
    }
};

#endif //ANALOGCOMPONENT_H
