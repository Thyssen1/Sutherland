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
	std::cout << "1: Go North.\n\n";
	std::cout << "2: Go East\n\n";
	std::cout << "3: Go West\n\n";
	std::cout << "4: Go South\n\n";
	std::cout << "5: Quit\n\n";
}

void Game::GetPlayerInput(std::string& playerInput) {
	std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput) {
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0) {
		std::cout << "You have chosen to Go North!\n";
		chosenOption = PlayerOptions::GoNorth;
	} 
	else if (playerInput.compare("2") == 0) {
		std::cout << "You have chosen to Go East!\n";
		chosenOption = PlayerOptions::GoEast;
	}
	else if (playerInput.compare("3") == 0) {
		std::cout << "You have chosen to Go West!\n";
		chosenOption = PlayerOptions::GoWest;
	}
	else if (playerInput.compare("4") == 0) {
		std::cout << "You have chosen to Go South!\n";
		chosenOption = PlayerOptions::GoSouth;
	}
	else if (playerInput.compare("5") == 0) {
		std::cout << "You have chosen to quit!\n";
		chosenOption = PlayerOptions::Quit;
	}
	else {
		std::cout << "I do not recognize that option. Try again!\n";
	}

	return chosenOption;
}

void Game::RunGame() {

	InitializeRooms();

	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false) {
		GivePlayerOptions();

		std::string playerInput;
		GetPlayerInput(playerInput);

		PlayerOptions selectedOption = EvaluateInput(playerInput);
		shouldEnd = (selectedOption == PlayerOptions::Quit);
		if (shouldEnd == false) {
			UpdateOnOption(selectedOption);
		}
	}
}

void Game::InitializeRooms() {
	// Room 0 heads North to Room 1
	m_rooms[0].AddRoom(Room::JoiningDirections::North, &(m_rooms[1]));

	// Room 1 heads East to Room 2, South 
	m_rooms[1].AddRoom(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddRoom(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddRoom(Room::JoiningDirections::West, &(m_rooms[3]));

	// Room 2 heads West to Room 1
	m_rooms[2].AddRoom(Room::JoiningDirections::West, &(m_rooms[1]));

	// Room 3 heads East to Room 1
	m_rooms[3].AddRoom(Room::JoiningDirections::East, &(m_rooms[1]));

	// Set player's current room to room 0
	m_player.SetCurrentRoom(&(m_rooms[0]));
}

void Game::UpdateOnOption(PlayerOptions selectedOption) {
	if (selectedOption == PlayerOptions::GoNorth || selectedOption == PlayerOptions::GoEast ||
		selectedOption == PlayerOptions::GoSouth || selectedOption == PlayerOptions::GoWest) {

		Room::JoiningDirections directionToMove = Room::JoiningDirections::North;

		switch (selectedOption) {
		case PlayerOptions::GoEast: { directionToMove = Room::JoiningDirections::East; } break;
		case PlayerOptions::GoWest: { directionToMove = Room::JoiningDirections::West; } break;
		case PlayerOptions::GoSouth: { directionToMove = Room::JoiningDirections::South; } break;
		}

		const Room* pPlayerCurrentRoom = m_player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(directionToMove);

		if (pNewRoom != nullptr) {
			m_player.SetCurrentRoom(pNewRoom);
		}
		else {
			const char* strDirection = "North";

			switch (selectedOption) {
			case PlayerOptions::GoEast: { strDirection = "East"; } break;
			case PlayerOptions::GoSouth: { strDirection = "South"; } break;
			case PlayerOptions::GoWest: { strDirection = "West"; } break;
			}
			std::cout << "There is no room to the " << strDirection << "\n\n";
		}
	}
}