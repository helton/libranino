#include <Arduino.h>
#include "../../src/Display/SevenSegmentDisplay.h"

using namespace Arduino;

const unsigned long waitMs = 1000;

SevenSegmentDisplay sevenSegmentDisplay(13, 12, 11, 10, 9, 8, 7, 6);

void setup() {
	Serial.begin(9600);
}

void loop() {
	sevenSegmentDisplay.write(SevenSegmentDisplay::zero);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::one);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::two);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::three);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::four);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::five);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::six);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::seven);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::eight);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::nine);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::A);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::B);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::C);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::D);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::E);
	delay(waitMs);
	sevenSegmentDisplay.write(SevenSegmentDisplay::F);
	delay(waitMs);
}
