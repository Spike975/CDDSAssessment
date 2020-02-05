#include "HashFunction.h"
#include <stdlib.h>

int main() {
	tHashmap<std::string, int> test;
	int input;
	int value;
	std::string key;
	test.setSize(50);

	while (true) {
		std::cout << "[1]  Enter New Hash\n[2]  Get Value\n[3]  Get Size\n[4]  Set Size\n[5]  Reset Hashmap\n[0]  Leave\n";
		std::cin >> input;
		if (input == 1) {
			std::cout << "Enter Key\n";
			std::cin >> key;
			std::cout << "Enter Value\n";
			std::cin >> value;
			if (std::cin.fail()) {
				system("CLS");
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Incorect values given.\n";
			}
			else {
				test.set(key, value);
			}
		}
		else if (input == 2) {
			std::cout << "Enter Key:\n";
			std::cin >> key;
			std::cout << test.at(key) << '\n';
		}
		else if (input == 3) {
			std::cout << "Current size: " << test.size() <<"\n";
		}
		else if (input == 4) {
			std::cout << "Enter new size:\n";
			std::cin >> input;
			test.setSize(input);
		}
		else if (input == 5) {
			test.reset();
			std::cout << "Reset Hashmap\n";
		}
		else if (input == 0) {
			std::cout << "Done With hashing\n";
			break;
		}
		else {
			std::cout << "No correct input recognized\n";
		}

		if (std::cin.fail()) {
			system("CLS");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	test.set("test", 5);

	std::cout << test["test"] << "\n";
	
	system("pause");

	return 0;
}