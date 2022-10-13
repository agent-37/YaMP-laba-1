#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <string> 

using namespace std;

template <typename T>
class Node {
public:
	T key;
	Node<T>* next;
	Node(const T& value = 0) : key(value) {}
};

template <class T>
class list {
private:
	Node<T>* head;
public:
	list() : head(NULL) {}
	~list() { clear(); }

	// добавление в  конец списка
	void add_back(const T& value);

	bool is_empty() const { return (head == NULL); }
	void print() const;

	// Очистка списка
	void clear() {
		Node<T>* tmp;
		while (head) {
			tmp = head->next;
			delete head;
			head = tmp;
		}
	}

};


template <class T>
void list<T>::add_back(const T& value) {
	if (is_empty()) {
		add_front(value);
		return;
	}
	Node<T>* new_elem = new Node<T>(value);
	new_elem->next = NULL;
	// Бежим до конца списка
	Node<T>* tmp = head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_elem;
}

template <class T>
void list<T>::print() const {
	Node<T>* tmp = head;
	cout << "List: ";
	while (tmp) {
		cout << tmp->key << " ";
		tmp = tmp->next;
	}
	cout << " end list." << endl;
}


#endif // _LIST_H_