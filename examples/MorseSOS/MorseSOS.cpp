#include "../../src/Morse/Morse.h"

using namespace Arduino;

Morse morse(9);

void setup() {
}

void loop() {
    morse.dot(); morse.dot(); morse.dot();
    morse.dash(); morse.dash(); morse.dash();
    morse.dot(); morse.dot(); morse.dot();
    delay(3000);
}
