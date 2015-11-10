#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <inttypes.h>
#include "../DataStructure/Queue.h"

namespace Arduino {
	typedef void (*Callback) ();
	
	class Timer {
	public:
		void update() {
			//to-do
		}
	private:
		Queue<Task> tasks;
	};
	
	class Task {
	public:
		Task(unsigned long interval, Callback callback) : _interval(interval), _callback(callback), _lastUpdate(millis()) { }
		bool isItTime() {
			return millis() - _lastUpdate >= _interval;
		}
		void execute() {
			_lastUpdate = millis();
			(*_callback)();
		}
	private:
		unsigned long _lastUpdate;
		unsigned long _interval;
		Callback _callback;
	};

}

#endif //TIMER_H
