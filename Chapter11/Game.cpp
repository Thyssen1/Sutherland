#include "Game.h"
#include <iostream>
#include <sstream>

Game::Game() :
	m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North"),
	m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East"),
	m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South"),
	m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West"),
	m_quitOption("Quit")
{
	m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
	m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[2] = dynamic_cast<Option*>(&m_moveWestOption);
	m_options[3] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

void Game::WelcomePlayer() {
	std::cout << "Welcome to Text Adventure!\n\n";
	std::cout << "What is your name?\n\n";

	std::string name;
	std::cin >> name;
	m_player.SetName(name);

	std::cout << "\nHello " << m_player.GetName() << "\n";
}

void Game::GivePlayerOptions() const {
	std::cout << "What would you like to do? (Enter a corresponding number)\n\n";

	for (unsigned int i = 0; i < m_numberOfOptions; ++i) {
		Option* option = m_options[i];
		const unsigned int chosenOption = i + 1;
		std::cout << chosenOption << ": " << option->GetOutputText() << "\n\n";

		std::ostringstream chosenOptionString;
		chosenOptionString << chosenOption;
		option->SetOptionText(chosenOptionString.str());
	}
}

void Game::GetPlayerInput(std::string& playerInput) {
	std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput) {
	PlayerOptions chosenOption = PlayerOptions::None;

	for (unsigned int i = 0; i < m_numberOfOptions; i++) {
		Option* option = m_options[i];
		bool handled = option->Evaluate(playerInput, m_player);

		if (handled == true) {
			chosenOption = option->GetChosenOption();
			break;
		}
	}

	if (chosenOption == PlayerOptions::None) {
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