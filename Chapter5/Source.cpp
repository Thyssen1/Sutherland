#include <iostream>

void PrintHello() {
	std::cout << "Hello \n";
}

void PrintSum(int valueA, int valueB) {
	std::cout << valueA + valueB << "\n";
}

int ReturnSum(int valueA, int valueB) {
	return valueA + valueB;
}

// Pass by pointer 
void ReturnSum(int inValueA, int inValueB, int* outValue) {
	*outValue = inValueA + inValueB;
}

// Pass by reference
void ReturnSum(int inValueA, int inValueB, int& outValue) {
	outValue = inValueA + inValueB;
}

struct SumParameters {
	int valueA;
	int valueB;
	int result;
};

void ReturnSum(SumParameters& params) {
	params.result = params.valueA + params.valueB;
}

void ReturnSum(SumParameters* params) {
	params->result = params->valueA + params->valueB;
}

struct Player {
	std::string m_name;
};

void WelcomePlayer(Player& player) {
	std::cout << "Welcome to Text Adventure!" << "\n\n";
	std::cout << "What is your name?\n";

	std::cin >> player.m_name;
	std::cout << "\nHello " << player.m_name << "\n";
}

int main() {

	PrintHello();

	PrintSum(3, 6);

	int sum = 0;
	ReturnSum(3, 6, &sum);
	std::cout << "Sum when passing by pointer: " << sum << "\n";

	ReturnSum(3, 6, sum);
	std::cout << "Sum when passing by reference: " << sum << "\n";


	SumParameters structsum;
	structsum.valueA = 3;
	structsum.valueB = 6;
	structsum.result = 0;

	ReturnSum(structsum);
	std::cout << "Sum when passing struct by reference: " << structsum.result << "\n";

	ReturnSum(&structsum);
	std::cout << "Sum when passing struct by pointer: " << structsum.result << "\n";

	// Adding Functions to Text Adventure
	Player player;
	WelcomePlayer(player);

	return 0;
}