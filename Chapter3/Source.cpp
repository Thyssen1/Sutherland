// Chapter 3 - Sutherland

#include <iostream>
#include <cmath>


int main()
{
	// Assignment operator
	int number1 = 1;
	int number2 = number1;

	char charNumber = 1;
	int intNumber = charNumber; // Implicit conversion from character to integer

	// Addition operator
	int sum = number1 + number2;

	int number = 1;
	number = number + number;

	// Subtraction operator
	number1 = 2;
	number2 = 1;

	int result = number1 - number2;

	// Multiplication and division operators
	number1 = 4;
	number2 = 2;

	int multiplied = number1 * number2;
	int divided = number1 / number2;

	int divided1 = number1 / number2; // Returns 2 since 2 divides into 4.
	int divided2 = number2 / number1; // Returns 0 since as 4 cannot divide into 2.

	number1 = 5;
	number2 = 2;

	divided1 = number1 / number2; // Returns 2 since 2 divides into 5 with a remainder of 1.
	divided2 = number2 / number1; // Returns 0 since 5 cannot divide into 2.

	float divided3 = static_cast<float>(number2) / static_cast<float>(number1); // Returns 2.5

	// Modulo operator
	int numerator = 12;
	int denominator = 10;
	int remainder = numerator % denominator; // Returns 2 since 12 (mod 10) = 2

	// Simple arithmetic calculators
	std::cout << "Enter your first number: \n";
	double num1;
	std::cin >> num1;

	std::cout << "Enter your second number: \n";
	double num2;
	std::cin >> num2;

	double add_result = num1 + num2;
	double sub_result = num1 - num2;
	double mul_result = num1 * num2;
	double div_result = num1 / num2;
	double rem_result = fmod(num1, num2);

	std::cout << "The result of adding the first and second numbers is: " << add_result << "\n";
	std::cout << "The result of subtracting the first and second numbers is: " << sub_result << "\n";
	std::cout << "The result of multiplying the numbers is: " << mul_result << "\n";
	std::cout << "The result of dividing the first number with the second is: " << div_result << "\n";
	std::cout << "The remainder from dividing the first number with the second is: " << rem_result << "\n";

	// Equality operators
	bool isEqual = num1 == num2;
	bool isNotEqual = num1 != num2;

	// Greater-than operators
	bool isGreaterThan = num1 > num2;
	bool isGreaterThanOrEqual = num1 >= num2;

	// Less-than operators
	bool isLessThan = num1 < num2;
	bool isLessThanOrEqual = num1 <= num2;

	// Simple comparison calculators
	std::cout << "It is " << isEqual << " that the numbers are equal.\n";
	std::cout << "It is " << isNotEqual << " that the numbers are not equal.\n";
	std::cout << "It is " << isGreaterThan << " that the first number is greater than the second.\n";
	std::cout << "It is " << isLessThan << " that the first number is less than the second.\n";

	// Bitwise operators
	double hex15 = 0x0F;
	std::cout << std::hex << hex15 << std::dec << "\n";

	// Binary & (AND) operator
	unsigned int first = 0x0F;
	unsigned int second = 0x18;
	unsigned int anded = first & second;
	
	std::cout << "Base of hexadecimal numbers: " << std::hex << std::showbase << "\n";
	std::cout << "First: " << first << "\n";
	std::cout << "Second: " << second << "\n";
	std::cout << "Anded: " << anded << "\n";

	// Binary | (OR) operator
	unsigned int ored = first | second;
	std::cout << "Ored: " << ored << "\n";

	// Binary ^ (Exclusive OR) operator
	unsigned int xored = first ^ second;
	std::cout << "XOred: " << xored << "\n";

	// Left shift (<<) operator
	unsigned int lshifted_first = first << 1;
	unsigned int lshifted_second = second << 1;
	std::cout << "First number shifted left by 1 bit: " << lshifted_first << "\n";
	std::cout << "Second number shifted left by 1 bit: " << lshifted_second << "\n";

	// Right shift (>>) operator
	unsigned int rshifted_first = first >> 1;
	unsigned int rshifted_second = second >> 1;
	std::cout << "First number shifted right by 1 bit: " << rshifted_first << "\n";
	std::cout << "Second number shifted right by 1 bit: " << rshifted_first << "\n";

	// && operator
	bool isTrue = true && true;
	bool isFalse = false && true;
	bool isFalse = true && false;
	bool isFalse = false && false;
	bool isTrue = true && true && true;

	// || operator
	bool isTrue = true || true;
	bool isTrue = false || true;
	bool isTrue = true || false;
	bool isFalse = false || false;
	bool isTrue = true || false || false;

	// Unary negative operator
	int negatedValue = -4;
	int positiveValue = -negatedValue;

	// Unary plus operator
	int valueA = 1;
	int valueB = +valueA;

	// Increment and decrement operators
	int value = 0;
	std::cout << value << "\n";		
	std::cout << value++ << "\n"; // Display. Then increment
	std::cout << ++value << "\n"; // Increment. Then display
	std::cout << value-- << "\n"; // Display. Then decrement.
	std::cout << --value << "\n"; // Decrement. Then display

	// Logical not operator
	int valueA = 0;
	int valueB = 2;
	bool notEqual = !(valueA == valueB);

	// One's complement operator
	int test = 0x0000000F;
	std::cout << std::hex << ~test << "\n"; // Bitflips of 0 to 1 and 1 to 0

	return 0;
}



