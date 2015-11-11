#include <Arduino.h>
#include "../../src/DataStructure/LinkedList.h"

using namespace Arduino;

void doItForAll(int value) {
	Serial.println("That's the value: " + String(value));
}

void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println("[Testing List]");
	Arduino::LinkedList<int> list;
	list.add(10);
	list.push(20);
	list.add(30);
	list.add(40);
	list.push(50);
	list.pop();
	list.remove(20);
	list.forEach(doItForAll);
	list.forEach([](int value) {
		Serial.println("Using lambda to get the value: " + String(value));
	});
	delay(5000);
}
