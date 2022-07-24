#include "Option.h"
#include <iostream>

void Option::SetOptionText(const std::string& optionText) {
	m_optionText = optionText;
}

const std::string& Option::GetOutputText() const {
	return m_outputText;
}

PlayerOptions Option::GetChosenOption() const {
	return m_chosenOption;
}

bool MoveOption::Evaluate(const std::string& optionText, Player& player) {
	bool handled = false;

	if (m_optionText.compare(optionText) == 0) {
		const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);

		if (pNewRoom != nullptr) {
			player.SetCurrentRoom(pNewRoom);
			std::cout << "You have chosen to " << m_outputText << "\n\n";
		}
		else {
			const char* strDirection = "North";
			switch (m_chosenOption)
			{
			case PlayerOptions::GoEast: { strDirection = "East"; } break;
			case PlayerOptions::GoSouth: { strDirection = "South"; } break;
			case PlayerOptions::GoWest: { strDirection = "West"; } break;
			}
			std::cout << "There is no room to the "
				<< strDirection << "\n\n";
		}
		handled = true;
	}
	return handled;
}

bool QuitOption::Evaluate(const std::string& optionText, Player& player) {
	m_shouldQuit = m_optionText.compare(optionText) == 0;	

	if (m_shouldQuit == true) {
		std::cout << "You have chosen to quit!\n\n";
	}

	return m_shouldQuit;
}