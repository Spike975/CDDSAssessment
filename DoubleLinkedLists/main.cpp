#include "DoubleLinkedList.h"

int main() {
	DoubleLinkedList<int> * test = new DoubleLinkedList<int>;
	test->pushBack(2);
	test->pushBack(5);
	test->pushBack(7);
	test->pushBack(3);
	test->popBack();

	test->resizeFront(2);

	test->readReverse();
	std::cout << "\n";
	test->readForward();

	return 0;
}