#include <Arduino.h>
#include <LiquidCrystal.h>
#include "../../src/Sensor/TemperatureSensor.h"

using namespace Arduino;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int temperatureSensor = 0; //LM35
const int lightSensor = 1; //LDR
const int button = 8;

/*
 [LM35 Specification]:
 Measure range: 10mV/ºC
 Max temperature: 150ºC
 Max voltage (based on max temperature): 150 * 10 = 1500mV = 1.5V
*/
TemperatureSensor lm35(0,    //analog pin 0 = A0
                       0.01, //0.01V/ºC = 10mV/ºC
                       150,  //150 ºC => using 1V as reference
                       5,    //5 volts
                       10,   //10 bits => 2 ^ 10 = 1024 values => range: 0 - 1023
                       Scale::CELSIUS);

void setup() {
	pinMode(lightSensor, INPUT);
	pinMode(button, INPUT);
	lcd.begin(16, 2);
}

void loop() {
	if (digitalRead(button) == HIGH) {
		if (lm35.getScale() == Scale::CELSIUS)
			lm35.setScale(Scale::FAHRENHEIT);
		else
			lm35.setScale(Scale::CELSIUS);
	}
	int light = analogRead(lightSensor);
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Temp.: " + lm35.getTemperatureAsString());
	lcd.setCursor(0, 1);
	lcd.print("Light: " + String(light));
	delay(500);
}
