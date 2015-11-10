#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>
#include <inttypes.h>

namespace Arduino {

	class Component {
	public:
		Component(uint8_t pin) : _pin(pin) { }
		uint8_t getPin() const {
			return _pin;
		}
		bool getState() {
			return digitalRead(_pin) == HIGH;
		}
		int getDigitalValue() {
			return digitalRead(_pin);
		}
		void off() {
			digitalWrite(_pin, LOW);
		}
		void on() {
			digitalWrite(_pin, HIGH);
		}
		void setDigitalValue(uint8_t value) {
			digitalWrite(_pin, value);
		}
	protected:
		uint8_t _pin;
	};

}

#endif //COMPONENT_H
