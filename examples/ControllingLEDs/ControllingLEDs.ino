#include "Common/Component.h"

const int ledPin = 13;
Component comp(ledPin);

void setup() {
	pinMode(ledPin, OUTPUT);
}

void loop() {
	comp.setDigitalValue(HIGH);
	delay(3000);
	comp.setDigitalValue(LOW);
	delay(3000);
}