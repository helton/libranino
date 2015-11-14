#include <Arduino.h>
#include "../../src/Display/CI4511.h"

using namespace Arduino;

CI4511 ci4511(4, 5, 6, 7);
const unsigned long waitMs = 1000;

void setup() {
}

void loop() {
	for(int i = 0; i < 10; i++) {
		ci4511.write(i);
		delay(waitMs);
	}
}
