#include "../../src/Timer/Timer.h"

using namespace Arduino;

const int ledPin = 13;
Timer timer(50);

void turnLedOnAndOff() {
	digitalWrite(ledPin, HIGH);
	delay(250);
	digitalWrite(ledPin, LOW);
	delay(250);
}

void setup() {
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	timer.addTask(Task(1000, turnLedOnAndOff, 3));
}

void loop() {
	timer.update();
}
