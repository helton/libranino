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
			node->item = value;
			node->next = nullptr;

			if (_head == nullptr)
				_head = node;
			if (_tail == nullptr)
				_tail = node;
			
			_tail->next = node;
			_tail = node;
			
			_size++;
		}
		T dequeue() {
			if (_size > 0) {
				Node* node = _head;
				T value = node->item;
				_head = _head->next;
				delete node;
				_size--;
				return value;
			}
			return T();
		}
		unsigned int getSize() const {
			return _size;
		}
	private:
		typedef struct Node {
			Node* next;
			T item;
		} Node;
		unsigned int _size;
		Node* _head;
		Node* _tail;
	};
	
}

#endif //QUEUE_H
