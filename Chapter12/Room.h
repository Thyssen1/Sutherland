#pragma once

#include "Entity.h"

class Room : public Entity {
public:
	enum class JoiningDirections {
		North = 0,
		East,
		South,
		West,
		Max
	};

	unsigned int Max = 10;

private:
	Room* m_pJoiningRooms[static_cast<unsigned int>(JoiningDirections::Max)];

public:
	Room();

	void AddRoom(JoiningDirections direction, Room* room);
	Room* GetRoom(JoiningDirections direction) const;
};