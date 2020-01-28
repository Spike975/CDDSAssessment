#pragma once

#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node * next;
	Node * prev;
};
template<typename T>
class DoubleLinkedList{
private:
	Node<T> * head;
	Node<T> * tail;
public:
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}
	DoubleLinkedList(const DoubleLinkedList & other) {
		head = other->head;
		tail = other->tail;
	}
	DoubleLinkedList & operator=(const DoubleLinkedList & other) {
		head = other->head;
		tail = other->tail;
	}
	~DoubleLinkedList() {
		delete[] head;
		delete[] tail;
	}

	void pushFront(const T & val) {
		Node<T> * temp = new Node<T>;
		temp->data = val;
		temp->next = NULL;
		if (head != NULL) {
			head->next = temp;
		}
		temp->prev = head;
		head = temp;
		
		tail = NULL;
		while (temp != NULL) {
			Node<T> * newTail = new Node<T>;
			newTail->data = temp->data;
			newTail->prev = NULL;
			if(tail != NULL){
				tail->prev = newTail;
			}
			newTail->next = tail;
			tail = newTail;
			temp = temp->prev;
		}
		delete temp;
	}
	void popFront() {
		if (head != NULL) {
			head = head->prev;
			head->next = NULL;
			Node<T> * temp = head;
			tail = NULL;
			while (temp != NULL) {
				Node<T> * newTail = new Node<T>;
				newTail->data = temp->data;
				newTail->prev = NULL;
				if (tail != NULL) {
					tail->prev = newTail;
				}
				newTail->next = tail;
				tail = newTail;
				temp = temp->prev;
			}
			head->next = NULL;
			delete temp;
		}
	}
	void pushBack(const T & val) {
		Node<T> * temp = new Node<T>;
		temp->data = val;
		temp->prev = NULL;
		if (tail != NULL) {
			tail->prev = temp;
		}
		temp->next = tail;
		tail = temp;
	
		head = NULL;
		while(temp != NULL){
			Node<T> * newHead = new Node<T>;
			newHead->data = temp->data;
			newHead->next = NULL;
			if (head != NULL) {
				head->next = newHead;
			}
			newHead->prev = head;
			head = newHead;
			temp = temp->next;
		}
		delete temp;
	}
	void popBack() {
		if (tail != NULL) {
			tail = tail->next;
			tail->prev = NULL;
			Node<T> * temp = tail;
			head = NULL;
			while (temp != NULL) {
				Node<T> * newHead = new Node<T>;
				newHead->data = temp->data;
				newHead->next = NULL;
				if (head != NULL) {
					head->next = newHead;
				}
				newHead->prev = head;
				head = newHead;
				temp = temp->next;
			}
			delete temp;
		}
	}

	void readForward() {
		Node<T> * temp = head;
		while (temp != NULL) {
			std::cout << temp->data << '\n';
			temp = temp->prev;
		}
		delete[] temp;
	}
	void readReverse() {
		Node<T> * temp = tail;
		while (temp != NULL) {
			std::cout << temp->data << '\n';
			temp = temp->next;
		}
		delete[] temp;
	}

	T & front() {
		if (head  != NULL) {
			return head->data;
		}
		else {
			std::cout << "No availible data";
		}
		return NULL;
	}
	const T & front() const{
		if (head != NULL) {
			return head->data;
		}
		else {
			std::cout << "No availible data";
		}
		return NULL;
	}
	T & back() {
		if (tail != NULL) {
			return tail->data;
		}
		else {
			std::cout << "No availible data";
		}
		return NULL;
	}
	const T & back() const {
		if (tail != NULL) {
			return tail->data;
		}
		else {
			std::cout << "No availible data";
		}
		return NULL;
	}

	void remove(const T & val) {
		if (head != NULL) {
			Node<T> * temp = head, *temp2 = head;
			if (temp != NULL && temp->data == val) {
				head = temp->prev;
				temp = head;
			}
			while (temp != NULL && temp->data != val) {
				temp2 = temp;
				temp = temp->prev;
			}
			if (temp == NULL) {
				return;
			}
			temp2->prev = temp->prev;
			remove(val);
			temp = head;
			tail = NULL;
			while (temp != NULL) {
				Node<T> * newTail = new Node<T>;
				newTail->data = temp->data;
				newTail->prev = NULL;
				if (tail != NULL) {
					tail->prev = newTail;
				}
				newTail->next = tail;
				tail = newTail;
				temp = temp->prev;
			}
			delete temp;
		}
		else {
			std::cout << "Node Empty";
		}
	}

	bool empty() const {
		if (head == NULL && tail == NULL) {
			return true;
		}
		return false;
	}
	void clear() {
		head = NULL;
		tail = NULL;
	}
	void resizeFront(size_t newSize) {
		if (newSize > 0) {
			Node<T> * temp = tail;
			head = NULL;
			for (int i = 0; i < newSize; i++) {
				if (temp != NULL) {
					pushFront(temp->data);
					temp = temp->next;
				}
				else {
					pushFront(0);
				}
			}
		}
		else {
			clear();
		}

	}
	void resizeBack(size_t newSize) {
		if (newSize > 0) {
			Node<T> * temp = head;
			tail = NULL;
			for (int i = 0; i < newSize; i++) {
				if (temp != NULL) {
					pushBack(temp->data);
					temp = temp->prev;
				}
				else {
					pushBack(0);
				}
			}
		}
		else {
			clear();
		}
	}

};