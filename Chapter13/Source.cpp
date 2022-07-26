#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ios>

// Aliases
using string = std::basic_string<char>;
using u16string = std::basic_string<char16_t>;
using u32string = std::basic_string<char32_t>;
using wstring = std::basic_string<wchar_t>;

void FindInString(std::string myString) {
	std::size_t found = myString.find("is");

	if (found != std::string::npos) {
		std::cout << "\" is \" found at position: " << found << "\n";
	}

	found = myString.find("is", found + 1);
	if (found != std::string::npos) {
		std::cout << "is found at position: " << found << "\n";
	}
}

int main() {
	std::string str = { "This is a is string!" };

	// Iterate through a string with an iterator 
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
		*iter = 'a';
		std::cout << *iter;
	}
	std::cout << "\n";

	// More modern way of iterating through a string
	// Range-based for loop
	for (char& it : str) {
		std::cout << it;
	}
	std::cout << "\n";

	// Declare constant such that it is clear that the program is read-only
	for (const char& it : str) {
		std::cout << it;
	}
	std::cout << "\n";

	// Best way to do it with auto keyword.
	for (const auto& it : str) {
		std::cout << it;
	}
	std::cout << "\n";

	// Using auto keyword with iterators
	for (auto it = str.cbegin(); it != str.cend(); it++) {
		std::cout << *it;
	}
	std::cout << "\n";

	// Iterate the end of the string to the beginning
	for (auto it = str.rbegin(); it != str.rend(); it++) {
		std::cout << *it;
	}
	std::cout << "\n";

	str = "This is a string";

	FindInString(str);

	std::cout << std::string::npos << "\n";

	std::size_t found = str.find_first_of("msg");
	if (found != std::string::npos) {
		std::cout << "msg found at position: " << found << "\n";
	}

	// Formatting data with stringstream
	std::stringstream myStringStream;

	myStringStream << "Hi\n";

	std::cout << "width: " << myStringStream.width() << "\n";
	myStringStream << 123 << "\n";
	myStringStream << std::setw(10) << 123 << "\n";
	myStringStream << std::setw(0) << 123 << "\n";

	myStringStream << 123.567 << "\n";
	myStringStream << std::setprecision(4) << 123.567 << "\n";
	myStringStream << std::fixed << std::setprecision(2) << 123.567 << "\n";
	myStringStream << std::defaultfloat << std::setprecision(0) << 123.567 << "\n";

	myStringStream << 110 << "\n" << std::showbase; 
	myStringStream << std::hex << 110 << "\n";
	myStringStream << std::oct << 110 << "\n";
	myStringStream << std::dec << 110 << "\n";

	string myString = myStringStream.str();

	std::cout << myString;

	return 0;
}