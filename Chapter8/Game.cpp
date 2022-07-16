#include "Game.h"
#include <iostream>

void Game::WelcomePlayer() {
	std::cout << "Welcome to Text Adventure!\n\n";
	std::cout << "What is your name?\n\n";

	std::string name;
	std::cin >> name;
	m_player.SetName(name);

	std::cout << "\nHello " << m_player.GetName() << "\n";
}

void Game::GivePlayerOptions() {
	std::cout << "What would you like to do? (Enter a corresponding number)\n\n";
	std::cout << "1: Quit\n\n";
}

void Game::GetPlayerInput(std::string& playerInput) {
	std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput) {
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0) {
		std::cout << "You have chosen to quit!\n\n";
		chosenOption = PlayerOptions::Quit;
	}
	else {
		std::cout << "I do not recognize that option. Try again!\n\n";
	}

	return chosenOption;
}

void Game::RunGame() {

	WelcomePlayer();

	bool shouldEnd = false;

	while (shouldEnd == false) {
		GivePlayerOptions();

		std::string playerInput;
		GetPlayerInput(playerInput);

		shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
	}
}