#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/Component.h"
#include "../Common/AsyncComponent.h"

namespace Arduino {

	typedef void (*Callback) (bool);

	class PushButton: public Component, public AsyncComponent {
	public:
		PushButton(uint8_t _pin) : Component(_pin), _lastState(LOW), _lastUpdateTime(0) { }
		void begin(unsigned long debounceTime, unsigned long interval) {
			_debounceTime = debounceTime;
			_interval = interval;
		}
		bool isOn() {
			return debounce() == HIGH;
		}
		bool isOff() {
			return debounce() == LOW;
		}
		void setCallbackWhenChangeState(Callback whenChangeState) {
			_whenChangeState = whenChangeState;
		}
		void update() override {
			unsigned long currentTime = millis();
			if (currentTime - _lastUpdateTime >= _interval) {
				_lastUpdateTime = currentTime;
				if (_lastState != debounce()) {
					(*_whenChangeState)(isOn());
				}
			}
		}
	private:
		int debounce() {
			int state = digitalRead(_pin);
			if (state != _lastState) {
				delay(_debounceTime); //To-Do: make it async
				state = digitalRead(_pin);
			}
			return state;
		}

		unsigned long _interval;
		unsigned long _lastUpdateTime;
		unsigned long _debounceTime;
		int _lastState;
		Callback _whenChangeState;
	};

}

#endif //PUSHBUTTON_H
