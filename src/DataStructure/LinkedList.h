#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace Arduino {

	template<typename T>
	class LinkedList {
	public:
		typedef void (*ForEachFunc) (T value);

		LinkedList() : _head(nullptr), _tail(nullptr), _size(0) { }
		~LinkedList() {
			while (_size > 0)
				pop();
		}
		void add(T value) {
			Node* node = new Node();
			node->value = value;
			node->prior = nullptr;
			node->next = nullptr;

			if (_head == nullptr)
				_head = node;
			if (_tail == nullptr)
				_tail = node;
			else {
				node->prior = _tail;
				_tail->next = node;
				_tail = node;
			}
			
			_size++;
		}
		void push(T value) {
			add(value);
		}
		T pop() {
			if (_size > 0) {
				T value = _tail->value;
				Node* node = _tail;

				_tail->prior->next = nullptr;
				_tail = _tail->prior;

				delete node;
				_size--;

				return value;
			}
		}
		void remove(T value) {
			Node* node = _head;
			while (node != nullptr) {
				if (node->value == value) {
					deleteNode(node);
					break;
				}
				else
					node = node->next;
			}			
		}
		void forEach(ForEachFunc forEachFunc) {
			Node* node = _head;
			while (node != nullptr) {
				(*forEachFunc)(node->value);
				node = node->next;
			}
		}
		T peek() {
			if (_tail != nullptr)
				return _tail->value;
		}
		unsigned int getSize() const {
			return _size;
		}
	private:
		typedef struct Node {
			Node* prior;
			Node* next;
			T value;
		} Node;
		Node* _head;
		Node* _tail;
		unsigned int _size;
		
		void deleteNode(Node* node) {
			Node* prior = node->prior;
			Node* next = node->next;
			if (prior == nullptr) {
				_head = next;
				next->prior = nullptr;
			}
			else
				prior->next = next;
			if (next == nullptr) {
				_tail = prior;
				prior->next = nullptr;
			}
			else
				next->prior = prior;
			delete node;
		}
	};
	
}

#endif //LINKEDLIST_H
