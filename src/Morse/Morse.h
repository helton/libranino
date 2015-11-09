#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>
#include <inttypes.h>

//To-Do: make it async

class Morse {
public:
	Morse(uint16_t pin) : _pin(pin) {
		pinMode(pin, OUTPUT);
		_shortTime = 250;
		_longTime = 1000;
	}
	void begin(unsigned long shortTime, unsigned int longTime) {
		_shortTime = shortTime;
		_longTime = longTime;
	}
	void dot() {
		digitalWrite(_pin, HIGH);
		delay(_shortTime);
		digitalWrite(_pin, LOW);
		delay(_shortTime);
	}
	void dash() {
		digitalWrite(_pin, HIGH);
		delay(_longTime);
		digitalWrite(_pin, LOW);
		delay(_shortTime);
	}

private:
	uint16_t _pin;
	unsigned long int _shortTime;
	unsigned long int _longTime;
};

#endif //MORSE_H
