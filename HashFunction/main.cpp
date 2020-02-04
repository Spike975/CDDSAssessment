#include "HashFunction.h"

int main() {
	tHashmap<std::string, int> test;

	test.setSize(50);

	test.set("test", 5);

	std::cout << test["test"] << "\n";
	
	system("pause");

	return 0;
}