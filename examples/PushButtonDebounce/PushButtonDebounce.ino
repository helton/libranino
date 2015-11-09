#include <LED.h>
#include <PushButton.h>

PushButton button(7);
LED led(13);

void setup() {
	button.begin(5);
}

void loop() {
    led.on();
    delay(1000);
    led.off();
    delay(1000);
}