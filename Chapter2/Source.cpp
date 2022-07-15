// Chapter 2 - Sutherland

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

// RAND_MAX is 32767

int main()
{
	srand(time(NULL));							// Set seed from current time
	unsigned int numberToGuess = rand() % 100;	// Get random number between 0 and 99 

	std::cout << "Guess a number between 0 and 99: ";
	unsigned int playersNumber;
	std::cin >> playersNumber;

	std::cout << "You guessed " << playersNumber << "\nThe actual number was " << numberToGuess << "\n";

	return 0;
}

