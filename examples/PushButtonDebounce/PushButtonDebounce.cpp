#include <Arduino.h>
#include "../../src/LED/LED.h"
#include "../../src/PushButton/PushButton.h"

using namespace Arduino;

PushButton button(8);
LED led(9);

int ledState = LOW;

void whenChangeState(bool buttonIsPressed) {
    if (buttonIsPressed)
        ledState += 51;
    if (ledState > 255)
        ledState = 0;
    led.setAnalogValue(ledState);
}

void setup() {
	button.begin(5, 50);
	button.setCallbackWhenChangeState(whenChangeState);
}

void loop() {
	button.update();
}

/*
const int ledPin = 11;
const int buttonPin = 2;

int ledState = false;
int lastButton = LOW;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

int debounce(int pin, int lastState) {
    int state = digitalRead(pin);
    if (state != lastState) {
        delay(5);
        state = digitalRead(pin);
    }
    return state;
}

void loop() {
    int buttonState = debounce(buttonPin, lastButton);
    if (lastButton == LOW && buttonState == HIGH) {
        ledState += 51;
        lastButton = HIGH;
    }
    else
        lastButton = buttonState;
    if (ledState > 255)
        ledState = 0;
    analogWrite(ledPin, ledState);
}
 * */
