#include <iostream>
#include <array>
#include <vector>

const unsigned int ARRAY_SIZE = 5;

using MyArray = std::array<int, ARRAY_SIZE>; // Create type alias
void FindInArray(MyArray myArray) {
	// Standard method of looping through array
	for (unsigned int i = 0; i < ARRAY_SIZE; i++) {
		if (myArray[i] == 2) {
			std::cout << "Found: " << myArray[i] << " at position: " << i << "\n";
		}
	}

	// Loop through array with iterator
	for (auto iter = myArray.begin(); iter != myArray.end(); iter++) {
		if (*iter == 2) {
			std::cout << "Found: " << *iter << "\n";
		}
	}

	// Modern style range-based method of looping through array
	for (auto& number : myArray) {
		if (number == 2) {
			std::cout << "Found: " << number << "\n";
		}
	}

	// Use STL algorithm to find the element we would like in this array
	MyArray::iterator found = find(myArray.begin(), myArray.end(), 2);
	if (found != myArray.end()) {
		std::cout << "Found: " << *found << "\n";
	}

}

using MyVector = std::vector<int>;
void FindInVector(MyVector myVector) {
	for (unsigned int i = 0; i < myVector.size(); i++) {
		if (myVector[i] == 2) {
			std::cout << "Found: " << myVector[i] << " at position: " << i << "\n";
		}
	}

	for (auto iter = myVector.begin(); iter != myVector.end(); iter++) {
		if (*iter == 2) {
			std::cout << "Found: " << *iter << "\n";
		}
	}

	for (auto& number : myVector) {
		if (number == 2) {
			std::cout << "Found: " << number << "\n";
		}
	}

	MyVector::iterator found = find(myVector.begin(), myVector.end(), 2);
	if (found != myVector.end()) {
		std::cout << "Found: " << *found << "\n";
	}
}

int main() {
	// Defining arrays
	int oldArray[ARRAY_SIZE] = { 0,1,2,3,4 };				// C-style array
	std::array<int, ARRAY_SIZE> newArray = { 0,1,2,3,4 };	// STL array container

	// Searching in an array
	FindInArray(newArray);

	// Specializing STL vector
	MyVector myVec = { 0,1,2 };
	myVec.push_back(3);
	myVec.push_back(4);

	// Vector insert and erase
	MyVector::const_iterator iter = myVec.begin() + 1;
	myVec.insert(iter, 5);
	myVec.erase(myVec.begin());
	//std::cout << *iter << "\n";

	for (auto& iter : myVec) {
		std::cout << iter << "\n";
	}

	// Iterate through vector
	FindInVector(myVec);

	return 0;
}