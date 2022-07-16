#include <iostream>


struct Player {
	std::string m_name;
};

void WelcomePlayer(Player& player) {
	std::cout << "Welcome to Text Adventure!" << "\n\n";
	std::cout << "What is your name?\n";

	std::cin >> player.m_name;
	std::cout << "\nHello " << player.m_name << "\n";
}

void GivePlayerOptions() {
	std::cout << "What would you like to do? (Enter a corresponding number) \n\n";
	std::cout << "1. Quit\n\n";
}

// Pass input by reference and prompt user to choose input
void GetPlayerInput(std::string& playerInput) {
	std::cin >> playerInput;
}

enum class PlayerOptions {
	Quit, 
	None
};

PlayerOptions EvaluateInput(std::string& playerInput) {
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

bool RunGame() {
	bool shouldEnd = false;

	GivePlayerOptions();

	std::string playerInput;
	GetPlayerInput(playerInput);

	shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;

	return !shouldEnd;
}

int main() {
	// Initialization
	Player player;
	WelcomePlayer(player);

	// Run game until player quits
	bool isPlaying = true;
	while (isPlaying) {
		isPlaying = RunGame();
	}

	return 0;
}