#ifndef RGBLED_H
#define RGBLED_H

#include <Arduino.h>
#include <inttypes.h>
#include "../Common/Color.h"

class RGBLED {
public:
    RGBLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin) { }
    void setColor(Color color) {
        analogWrite(_redPin,   color.getRed());
        analogWrite(_greenPin, color.getGreen());
        analogWrite(_bluePin,  color.getBlue());
    }
    void gradient(Color beginColor, Color endColor, float percent, unsigned long delayMs) {
    	if (beginColor.getValue() >= endColor.getValue()) {
			Color gradedColor = Color::gradedValue(beginColor, endColor, percent);
			Serial.println("RGB(" + String(gradedColor.getRed()) + ", " + String(gradedColor.getGreen()) + ", " + String(gradedColor.getBlue()) + ")");
			setColor(gradedColor);
			delay(delayMs);
			gradient(beginColor, gradedColor, percent, delayMs);
    	}
    }
private:
    uint8_t _redPin;
    uint8_t _greenPin;
    uint8_t _bluePin;
};

#endif //RGBLED_H
