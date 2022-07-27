#include <bitset>
#include <iostream>

const unsigned int NUMBER_OF_BITS = 5;

using MyBitset = std::bitset<NUMBER_OF_BITS>;

int main() {
	MyBitset defaultConstructor;							// Initialize all bits to 0
	MyBitset unsignedLongConstructor{ 0x17 };				// Hexadecimal
	MyBitset stringConstructor{ std::string{ "11011" } };	// Bits

	std::cout << std::boolalpha;

	std::cout << "Size of the bitset: " << stringConstructor.size() << "\n";
	std::cout << "Number of set bits: " << stringConstructor.count() << "\n";

	std::cout << "Is any bit set? " << stringConstructor.any() << "\n";
	std::cout << "Are all bits set? " << stringConstructor.all() << "\n";
	std::cout << "Are no bits set? " << stringConstructor.none() << "\n";

	for (unsigned int i = 0; i < stringConstructor.size(); i++) {
		// Query
		std::cout << "Bit " << i << " value: " << stringConstructor[i] << "\n";
		std::cout << "Bit " << i << " test: " << stringConstructor.test(i) << "\n"; 
	}

	stringConstructor.set(1, false);
	stringConstructor.set(1);
	stringConstructor.set();
	stringConstructor.reset(0);
	stringConstructor.reset();
	stringConstructor.flip(4);
	stringConstructor.flip();

	return 0;
}