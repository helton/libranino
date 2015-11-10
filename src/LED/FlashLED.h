#ifndef FLASHLED_H
#define FLASHLED_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/AsyncComponent.h"
#include "LED.h"

namespace Arduino {

	class FlashLED : public LED, public AsyncComponent {
	public:
		FlashLED(uint8_t pin) : LED(pin) { }
		void begin(long on, long off) {
			_onTime = on;
			_offTime = off;
			_ledState = LOW;
			_previousTime = 0;
		}
		void update() override {
			unsigned long currentTime = millis();
			if((_ledState == HIGH) && (currentTime - _previousTime >= _onTime)) {
				_ledState = LOW;
				_previousTime = currentTime;
				setDigitalValue(_ledState);
			}
			else if ((_ledState == LOW) && (currentTime - _previousTime >= _offTime)) {
				_ledState = HIGH;
				_previousTime = currentTime;
				setDigitalValue(_ledState);
			}
		}
	private:
		long _onTime;
		long _offTime;
		uint8_t _ledState;
		unsigned long _previousTime;
	};

}

#endif //FLASHLED_H
