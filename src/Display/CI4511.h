#ifndef CI4511_H
#define CI4511_H

#include <inttypes.h>

//To-do: Merge with SevenSegmentDisplay
namespace Arduino {
	class CI4511 {
	public:
		CI4511(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD) : _pinA(pinA), _pinB(pinB), _pinC(pinC), _pinD(pinD) {
			for (int i = 0; i < pinsCount; i++)
				pinMode(_CI4511Pins[i], OUTPUT);
		}
		void write(uint8_t binValue) {
			unsigned int mask, state;
			for (int i = 0; i < pinsCount; i++) {
				mask = 1 << (pinsCount - 1 - i);
				state = (binValue & mask) >> (pinsCount - 1 - i); //HIGH, LOW
				if (digitalRead(_CI4511Pins[i]) != state)
					digitalWrite(_CI4511Pins[i], state);
			}
		}
	private:
		static const uint8_t pinsCount = 4;
		uint8_t _pinA;
		uint8_t _pinB;
		uint8_t _pinC;
		uint8_t _pinD;
		uint8_t _CI4511Pins[pinsCount] = { _pinD, _pinC, _pinB, _pinA };
	};
}

#endif //CI4511_H
