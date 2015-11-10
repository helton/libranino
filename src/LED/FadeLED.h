#ifndef FADELED_H
#define FADELED_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/AsyncComponent.h"
#include "LED.h"

namespace Arduino {

	enum class FadeType {
		FADE_IN, FADE_OUT, FADE_IN_OUT
	};

	class FadeLED : public LED, public AsyncComponent {
	public:
		FadeLED(uint8_t pin) : LED(pin) { }
		void begin(FadeType fadeType, unsigned long interval, unsigned int brightnessLevels) {
			_fadeType = fadeType;
			_interval = interval;
			_brightnessLevels = brightnessLevels;
			_previousTime = 0;
			switch (_fadeType) {
				case FadeType::FADE_IN:
				case FadeType::FADE_IN_OUT:
					_brightness = MIN_PWM;
					_increaseBrightness = true;
					break;
				case FadeType::FADE_OUT:
					_brightness = MAX_PWM;
					_increaseBrightness = false;
					break;
			}
		}
		void update() override {
		unsigned long currentTime = millis();
			if (currentTime - _previousTime >= _interval) {
				int incrementDecrement = MAX_PWM / _brightnessLevels;
				_previousTime = currentTime;
				setAnalogValue(_brightness);
				if (_fadeType == FadeType::FADE_IN_OUT) {
					if (_brightness >= MAX_PWM)
						_increaseBrightness = false;
					else if (_brightness <= MIN_PWM)
						_increaseBrightness = true;
				}
				if (_increaseBrightness) {
					_brightness += incrementDecrement;
					if (_brightness > MAX_PWM)
						_brightness = MIN_PWM;
				}
				else {
					_brightness -= incrementDecrement;
					if (_brightness < MIN_PWM)
						_brightness = MAX_PWM;
				}
			}
		}
	private:
		FadeType _fadeType;
		unsigned long _interval;
		unsigned int _brightnessLevels;
		unsigned long _previousTime;
		int _brightness;
		bool _increaseBrightness;
	};

}

#endif //FADELED_H
