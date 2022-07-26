#include "ListNode.h"
#include <list>
#include <iostream>

bool Descending(int first, int second) {
	return first > second;
}

using MyList = std::list<int>;
void SortList() {
	MyList myList = { 0,1,2,3,4 };
	myList.sort(Descending);

	for (auto& value : myList) {
		std::cout << value << "\n";
	}
	std::cout << "\n";

	myList.sort();
	for (auto& value : myList) {
		std::cout << value << "\n";
	}
}

int main() {
	// Print numbers in the doubly linked list
	OurList();

	//
	MyList myList = { 0,1,2 };
	myList.push_back(3);
	myList.push_back(4);
	MyList::const_iterator iter = myList.cbegin();
	++iter;

	iter = myList.insert(iter, 5);
	//myList.erase(iter);

	for (auto& iter : myList) {
		std::cout << iter << "\n";
	}

	// Sort list 
	SortList();

	return 0;
}






