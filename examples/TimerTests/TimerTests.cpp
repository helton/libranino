#include "../../src/Timer/Timer.h"
#include "../../src/DataStructure/Queue.h"

using namespace Arduino;

Queue<String> queue;

void setup() {
	Serial.begin(9600);
}

void loop() {
	queue.enqueue("A");
	queue.enqueue("B");
	queue.enqueue("C");
	Serial.println(queue.dequeue());
	Serial.println("Size: " + String(queue.getSize()));
	Serial.println(queue.dequeue());
	Serial.println("Size: " + String(queue.getSize()));
	Serial.println(queue.dequeue());
	Serial.println("Size: " + String(queue.getSize()));
	delay(3000);
}
