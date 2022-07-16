#pragma once

#include "Player.h"
#include "PlayerOptions.h"

class Game {
private:
	Player m_player;

	void WelcomePlayer();
	void GivePlayerOptions();
	void GetPlayerInput(std::string& playerInput);
	PlayerOptions EvaluateInput(std::string& playerInput);

public:
	void RunGame();
};
