#include "DoubleLinkedList.h"

int main() {
	DoubleLinkedList<int> * test = new DoubleLinkedList<int>;
	test->pushBack(2);
	test->pushBack(6);
	test->pushBack(8);
	test->pushBack(4);
	test->pushFront(1);
	test->pushFront(7);
	test->pushFront(5);
	test->pushFront(3);

	//test->popBack();
	//test->popFront();

	//test->remove(5);

	test->readReverse();
	std::cout << "\n";
	test->readForward();
	std::cout << "\n";

	//test->resizeBack(5);
	//test->resizeFront(8);

	test->sortUp();

	test->readForward();
	std::cout << "\n";
	test->readReverse();
	std::cout << "\n";

	//test->clear();

	if (test->empty()) {
		std::cout << "List is empty\n";
	}
	else {
		std::cout << "List isn\'t empty\n";
	}

	system("pause");
	return 0;
}