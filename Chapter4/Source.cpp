#include <iostream>
#include <string>

int main()
{
	// C++ array
	int intArray[5] = { 0,1,2,3,4 };

	for (int index = 0; index < 5; index++) {
		std::cout << "Index: " << index << "\n";
		std::cout << "Value: " << intArray[index] << "\n";
	}

	// Pointers		
	int variable = 5;					// Create variable to hold integer value 5
	int* variablePointer = &variable;	// Create pointer to variable

	std::cout << "Value of variable: " << variable << "\n";
	std::cout << "Address of variable: " << &variable << "\n";

	std::cout << "Value of variablePointer: " << variablePointer << "\n";
	std::cout << "Address of variablePointer: " << &variablePointer << "\n";

	std::cout << "Value of memory at dereferenced variablePointer: " << *variablePointer << "\n";
	std::cout << "Value of memory at dereferenced variablePointer + 1: " << *variablePointer + 1 << "\n";

	// Pointer arithmetic
	std::cout << "Value of variablePointer: " << variablePointer << "\n";
	std::cout << "Value of variablePointer + 1: " << variablePointer + 1 << "\n";

	// Pointers and arrays
	for (int index = 0; index < 5; index++) {
		std::cout << "Index: " << index << "\n";
		std::cout << "Dereferenced value: " << *(intArray+index) << "\n";
	}

	// C style strings in arrays
	const char* cStyleString = "CStyleString";			// String literal of size 12
	std::cout << (cStyleString[12] == '\0') << "\n";	// Null terminator is at end of string

	// Working with C Style Strings
	std::cout << "strlen of cStyleString is: " << std::strlen(cStyleString) << "\n";

	std::cout << "strcmp of cStyleString and cStyleString is: " << std::strcmp(cStyleString, cStyleString) << "\n";

	char cStyleStringCpy[13];
	std::strcpy(cStyleStringCpy, cStyleString);
	std::cout << "cStyleString was copied into cStyleStringCpy: " << cStyleStringCpy << "\n";

	std::strcat(cStyleStringCpy, cStyleString);
	std::cout << "cStyleStringCpy was extended by using concatenation: " << cStyleStringCpy << "\n";

	// Text adventure game
	std::cout << "Hello. Welcome to Text Adventure. What is your name?\n";
	std::string PlayerName;
	std::cin >> PlayerName;

	std::cout << "Hello " << PlayerName << "\n";

	return 0;
}