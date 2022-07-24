#include "PlayerOptions.h"
#include "Room.h"
#include "Option.h"

class Game {
private:
	static const unsigned int m_numberOfRooms = 4;
	Room m_rooms[m_numberOfRooms];

	Player m_player;

	MoveOption m_moveNorthOption;
	MoveOption m_moveEastOption;
	MoveOption m_moveSouthOption;
	MoveOption m_moveWestOption;
	QuitOption m_quitOption;

	static const unsigned int m_numberOfOptions = 5;
	Option* m_options[m_numberOfOptions];

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& playerInput);
	PlayerOptions EvaluateInput(std::string& playerInput);
	void UpdateOnOption(PlayerOptions selectedOption);

public:
	Game();

	void RunGame();
};