#include "DoubleLinkedList.h"
#include <stdlib.h>

int main() {
	DoubleLinkedList<int> test;
	int input;
	while (true) {
		std::cout << "What would you like to do?\n[1]  Add Number\n[2]  Remove\n[3]  Resize\n[4]  Print Numbers\n[5]  Sort List\n[6]  Check if empty\n[7]  Clear List\n[8]  Finished\n";
		std::cin >> input;
		std::cout << '\n';
		if (input == 1) {//Adding numbers
			std::cout << "[1]  Front\n[2]  Back\n";
			std::cin >> input;
			if (input == 1) {
				std::cout << "Enter Number:\n";
				std::cin >> input;
				test.pushFront(input);
			}
			else if (input == 2) {
				std::cout << "Enter Number:\n";
				std::cin >> input;
				test.pushBack(input);
			}
			else {
				std::cout << "Not correct input\n";
			}
			system("CLS");
		}
		else if (input == 2) {//Removing numbers
			std::cout << "[1]  Front\n[2]  Back\n[3]  Certain Number\n";
			std::cin >> input;
			if (input == 1) {
				test.popFront();
				std::cout << "Front popped\n";
			}
			else if (input == 2) {
				test.popBack();
				std::cout << "Back popped\n";
			}
			else if (input == 3) {
				std::cout << "Enter Number:\n";
				std::cin >> input;
				test.remove(input);
			}
			else {
				std::cout << "Not correct input\n";
			}
			system("CLS");
		}
		else if (input == 3) {//Resizing list
			std::cout << "[1]  Front\n[2]  Back\n";
			std::cin >> input;
			if (input == 1) {
				std::cout << "Enter number for new length\n";
				std::cin >> input;
				test.resizeFront(input);
			}
			else if (input == 2) {
				std::cout << "Enter number for new length\n";
				std::cin >> input;
				test.resizeBack(input);
			}
			else {
				std::cout << "Not correct input\n";
			}
			system("CLS");
		}
		else if (input == 4) {//Printing numbers
			std::cout << "[1]  From Front\n[2]  From Back\n";
			std::cin >> input;
			system("CLS");
			if (input == 1) {
				test.readForward();
				std::cout << '\n';
			}
			else if (input == 2) {
				test.readReverse();
				std::cout << '\n';
			}
			else {
				std::cout << "Not correct input\n";
			}
		}
		else if (input == 5) {//Sorting
			std::cout << "[1]  Front\n[2]  Back\n";
			std::cin >> input;
			std::cout << '\n';
				system("CLS");
			if (input == 1) {
				test.sortUp();
				std::cout << "Sorted Greatest to Least\n\n";
			}
			else if (input == 2) {
				test.sortDown();
				std::cout << "Sorted Least to Greatest\n\n";
			}
			else {
				std::cout << "Not correct input\n\n";
			}
		}
		else if (input == 6) {//Checking if empty
			system("CLS");
			if (test.empty()) {
				std::cout << "List is empty\n\n";
			}
			else {
				std::cout << "List isn\'t empty\n\n";
			}
		}
		else if (input == 7) {//Clear list
			test.clear();
			system("CLS");
			std::cout << "Cleared List\n\n";
		}
		else if (input == 8) {//Done
			std::cout << "List done\n";
			break;
		}
		else {
			std::cout << "No given entry\n";
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	test.sortUp();

	return 0;
}