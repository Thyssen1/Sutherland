#include "Player.h"
#include "GameLoop.h"

int main() {
	Player player;
	GameLoop::WelcomePlayer(player);

	bool isPlaying = true;
	while (isPlaying) {
		isPlaying = GameLoop::RunGame();
	}

	return 0;
}