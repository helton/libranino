#ifndef QUEUE_H
#define QUEUE_H

namespace Arduino {

	template<typename T>
	class Queue {
	public:
		Queue() : _head(nullptr), _tail(nullptr), _size(0) { }
		~Queue() {
			while (_size > 0)
				dequeue();
		}
		void enqueue(T value) {
			Node* node = new Node();
			node->value = value;
			node->next = nullptr;

			if (_head == nullptr)
				_head = node;
			if (_tail == nullptr)
				_tail = node;
			else {
				_tail->next = node;
				_tail = node;
			}
			
			_size++;
		}
		T dequeue() {
			if (_size > 0) {
				Node* node = _head;
				T value = node->value;
				_head = _head->next;
				delete node;
				_size--;
				return value;
			}
		}
		T peek() {
			if (_head != nullptr)
				return _head->value;
		}
		unsigned int getSize() const {
			return _size;
		}
	private:
		typedef struct Node {
			Node* next;
			T value;
		} Node;
		Node* _head;
		Node* _tail;
		unsigned int _size;
	};
	
}

#endif //QUEUE_H