#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <inttypes.h>
#include "../DataStructure/Queue.h"
#include "../DataStructure/LinkedList.h"

namespace Arduino {

	typedef void (*Callback) ();

	class Task {
	public:
		Task(unsigned long interval, Callback callback, unsigned long numberOfExpectedExecutions) : _interval(interval), _callback(callback), _numberOfExpectedExecutions(numberOfExpectedExecutions), _lastUpdate(millis()), _numberOfExecutions(0) { }
		bool canExecute() const {
			if (canRemove())
				return false;
			return millis() - _lastUpdate >= _interval;
		}
		bool canRemove() const {
			return _numberOfExecutions == _numberOfExpectedExecutions;
		}
		void execute() {
			_lastUpdate = millis();
			_numberOfExecutions++;
			(*_callback)();
		}
		bool operator==(const Task& anotherTask) {
			return (anotherTask._lastUpdate == this->_lastUpdate) &&
					(anotherTask._interval == this->_interval) &&
					(anotherTask._callback == this->_callback) &&
					(anotherTask._numberOfExpectedExecutions == this->_numberOfExpectedExecutions) &&
					(anotherTask._numberOfExecutions == this->_numberOfExecutions);
		}
	protected:
		unsigned long _lastUpdate;
		unsigned long _interval;
		Callback _callback;
		unsigned long _numberOfExpectedExecutions;
		unsigned long _numberOfExecutions;
	};

	class Timer {
	public:
		Timer(unsigned long sweepInterval) : _lastUpdate(0), _sweepInterval(sweepInterval) { }
		void addTask(Task task) {
			_tasks.add(task);
		}
		void update() {
			unsigned long current = millis();
			if (current - _lastUpdate >= _sweepInterval) {
				_lastUpdate = current;
				LinkedList<Task>::ForEachFunc forEachFunc = [/*&_tasks*/](Task task) {
					if (task.canExecute())
						task.execute();
					/*if (task.canRemove())
						_tasks.remove(task);*/
				};
				_tasks.forEach(forEachFunc);
			}
		}
	private:
		unsigned long _lastUpdate;
		unsigned long _sweepInterval;
		LinkedList<Task> _tasks;
	};

};

#endif //TIMER_H
