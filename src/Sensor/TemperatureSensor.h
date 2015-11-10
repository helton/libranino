#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <Arduino.h>

namespace Arduino {

	enum class Scale {
		CELSIUS, FAHRENHEIT
	};

	class TemperatureSensor {
	public:
		TemperatureSensor(unsigned int pin, float voltagePerCelsius,
				unsigned int maxTemperature, unsigned int realMaxVoltage,
				unsigned int bitResolution, Scale scale) :
				_pin(pin), _voltagePerCelsius(voltagePerCelsius), _maxTemperature(
						maxTemperature), _realMaxVoltage(realMaxVoltage), _bitResolution(
						bitResolution), _scale(scale) {
			pinMode(_pin, INPUT);
		}
		float getTemperature() {
			/*
			 [Relation temperature vs voltage]
			 maxTemperature     = maxTemperature * voltagePerCelsius
			 realMaxTemperature = realMaxVoltage
			 -------------------------------------------------------------------------------------------------
			 realMaxTemperature = (realMaxVoltage * maxTemperature) / (maxTemperature * voltagePerCelsius) = realMaxVoltage / voltagePerCelsius
			 */
			unsigned int realMaxTemperature = _realMaxVoltage / _voltagePerCelsius;

			/*
			 [Relation temperature vs valueReadBySensor(adc)]
			 realMaxTemperature = (1 << bitResolution) - 1
			 temperature        = adc (analog-digital conversor)
			 ---------------------------------------------
			 temperature = (realMaxTemperature * adc) / ((1 << bitResolution) - 1)
			 */
			unsigned int adc = analogRead(_pin);
			float celsius = (realMaxTemperature * adc)
					/ ((1 << _bitResolution) - 1);
			if (_scale == Scale::CELSIUS)
				return celsius;
			return celsius * 1.8 + 32; //Celsius to Fahrenheit
		}
		String getTemperatureAsString() {
			return String(getTemperature())
					+ (_scale == Scale::CELSIUS ? " *C" : " *F");
		}
		Scale getScale() const {
			return _scale;
		}
		void setScale(Scale scale) {
			_scale = scale;
		}
	private:
		unsigned int _pin;
		float _voltagePerCelsius;
		unsigned int _maxTemperature;
		unsigned int _realMaxVoltage; //use analogReference(INTERNAL) to get 1.1V as reference (caution with that), otherwise you'll get the default 5V
		unsigned int _bitResolution;
		Scale _scale;
	};

}

#endif TEMPERATURESENSOR_H
