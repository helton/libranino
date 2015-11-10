#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/AnalogComponent.h"

namespace Arduino {

	const int MIN_PWM = 0x0;
	const int MAX_PWM = 0xFF;

	class LED : public AnalogComponent {
	public:
		LED(uint8_t pin) : AnalogComponent(pin) {
			pinMode(_pin, OUTPUT);
		}
		void blink(unsigned long waitTime, unsigned long times) {
			for (int i = 0; i < times; i++) {
				toggle();
				delay(waitTime);
			}
		}
		void toggle() {
			digitalWrite(_pin, getState() ? LOW : HIGH);
		}
	};

}

#endif //LED_H
