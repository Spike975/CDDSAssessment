#include "DoubleLinkedList.h"

int main() {
	DoubleLinkedList<int> * test = new DoubleLinkedList<int>;
	test->pushBack(2);
	test->pushBack(5);
	test->pushFront(7);
	test->pushFront(3);

	test->popBack();
	test->popFront();

	test->remove(5);

	test->readReverse();
	std::cout << "\n";
	test->readForward();
	std::cout << "\n";

	test->resizeBack(5);
	test->resizeFront(8);

	test->readReverse();
	std::cout << "\n";
	test->readForward();
	std::cout << "\n";

	test->clear();

	if (!test->empty()) {
		std::cout << "List is empty";
	}
	else {
		std::cout << "List isn\'t empty";
	}

	return 0;
}