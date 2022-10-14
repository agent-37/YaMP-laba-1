#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <string> 
#include <fstream>
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
	void add_front(const T& value);
	// добавление в  конец списка
	void add_back(const T& value);

	bool is_empty() const { return (head == NULL); }
	//записывает в файл
	void print(ofstream &fout, int begin_number);
	//проверяет есть ли элемент в хеше
	bool find(const T& value);
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
void list<T>::add_front(const T& value) {
	if (is_empty()) {
		head = new Node<T>(value);
		head->next = NULL;
	}
	else
	{
		Node<T>* tmp = new Node<T>(value);
		tmp->next = head;
		head = tmp;
	}
}
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
void list<T>::print (ofstream &fout , int begin_number)   {
	Node<T>* tmp = head;	
	while (tmp) {
		fout <<begin_number<<' '<< tmp->key ;
		tmp = tmp->next;
	}
}
template <class T>
bool list<T>::find(const T& value) {
	Node<T>* tmp = head;
	while (tmp) {
		if (value == tmp->key)
			return true;
		tmp = tmp->next;
	}
	return false;
}

#endif // _LIST_H_