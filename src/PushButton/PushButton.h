#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/Component.h"

class PushButton : public Component {
public:
    PushButton(uint8_t _pin) : Component(_pin) { }
    void begin(uint8_t debounceMiliseconds) {
        _debounceMiliseconds = debounceMiliseconds;
    }
private:
	uint8_t _debounceMiliseconds;
};

#endif //PUSHBUTTON_H