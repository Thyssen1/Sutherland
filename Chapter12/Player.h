#pragma once

#include <string>
#include "Entity.h"
#include "Room.h"

class Player : public Entity {
private:
	const Room* m_pCurrentRoom;
	std::string m_name;

public:
	Player() {}
	Player(const std::string& name) : m_name(name) {}

	~Player() {}

	Player(const Player& originalPlayer);
	Player(Player&& tempPlayer) noexcept;

	void SetName(const std::string& name);
	void SetName(const std::string& forename, const std::string& surname);

	void operator+=(const std::string& name);

	const Player& operator=(const Player& player);

	Player& operator=(Player&& tempPlayer) noexcept;

	const std::string& GetName() const;

	void SetCurrentRoom(const Room* pCurrentRoom);

	const Room* GetCurrentRoom() const;

};