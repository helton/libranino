#ifndef SEVENSEGMENTDISPLAY_H
#define SEVENSEGMENTDISPLAY_H

#include <inttypes.h>

//To-do: Merge with CI4511
namespace Arduino {
	class SevenSegmentDisplay {
	public:
		SevenSegmentDisplay(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinH) : _pinA(pinA), _pinB(pinB), _pinC(pinC), _pinD(pinD), _pinE(pinE), _pinF(pinF), _pinG(pinG), _pinH(pinH) {
			for (int i = 0; i < pinsCount; i++)
				pinMode(_sevenSegmentDisplayPins[i], OUTPUT);
		}
		void write(uint8_t hexValue) {
			unsigned int mask, state;
			for (int i = 0; i < pinsCount; i++) {
				mask = 1 << (pinsCount - 1 - i);
				state = (hexValue & mask) >> (pinsCount - 1 - i); //HIGH, LOW
				if (digitalRead(_sevenSegmentDisplayPins[i]) != state)
					digitalWrite(_sevenSegmentDisplayPins[i], state);
			}
		}
		//                                    ABCDEFGH(.)
		static const uint8_t zero  = 0xFC; //11111100
		static const uint8_t one   = 0x60; //01100000
		static const uint8_t two   = 0xDA; //11011010
		static const uint8_t three = 0xF2; //11110010
		static const uint8_t four  = 0x66; //01100110
		static const uint8_t five  = 0xB6; //10110110
		static const uint8_t six   = 0xBE; //10111110
		static const uint8_t seven = 0xE0; //11100000
		static const uint8_t eight = 0xFE; //11111110
		static const uint8_t nine  = 0xF6; //11110110
		static const uint8_t A     = 0xEE; //11101110
		static const uint8_t B     = 0x3E; //00111110
		static const uint8_t C     = 0x9C; //10011100
		static const uint8_t D     = 0x7A; //01111010
		static const uint8_t E     = 0x9E; //10011110
		static const uint8_t F     = 0x8E; //10001110
	private:
		static const uint8_t pinsCount = 8;
		uint8_t _pinA;
		uint8_t _pinB;
		uint8_t _pinC;
		uint8_t _pinD;
		uint8_t _pinE;
		uint8_t _pinF;
		uint8_t _pinG;
		uint8_t _pinH;
		uint8_t _sevenSegmentDisplayPins[pinsCount] = { _pinA, _pinB, _pinC, _pinD, _pinE, _pinF, _pinG, _pinH };
	};
}

#endif //SEVENSEGMENTDISPLAY_H
