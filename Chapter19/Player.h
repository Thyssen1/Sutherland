#pragma once

#include <string>
#include <vector>
#include "Entity.h"
#include "Item.h"
#include "Sword.h"
#include "Room.h"

class Player
	: public Entity
{
private:
	using Items = std::vector<Item*>;
	Items m_items;

	Room* m_pCurrentRoom;
	std::string m_name;

public:
	Player()
	{
	}

	Player(const Player& originalPlayer)
	{
		m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
		m_name = originalPlayer.m_name;
	}

	Player& operator=(const Player& originalPlayer)
	{
		m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
		m_name = originalPlayer.m_name;
		return *this;
	}

	Player(Player&& tempPlayer)
	{
		m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
		m_name = tempPlayer.m_name;

		tempPlayer.m_pCurrentRoom = nullptr;
		m_name.clear();
	}

	Player& operator=(Player&& tempPlayer)
	{
		if (this != &tempPlayer)
		{
			m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
			m_name = tempPlayer.m_name;

			tempPlayer.m_pCurrentRoom = nullptr;
			m_name.clear();
		}

		return *this;
	}

	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}

	void SetCurrentRoom(Room* pCurrentRoom)
	{
		m_pCurrentRoom = pCurrentRoom;
	}

	Room* GetCurrentRoom() const
	{
		return m_pCurrentRoom;
	}

	void AddItem(const Item* item)
	{
		m_items.push_back(const_cast<Item*>(item));
	}

	bool HasWeapon()
	{
		bool hasWeapon = false;

		for (const Item* item : m_items)
		{
			const Sword* sword = dynamic_cast<const Sword*>(item);
			if (sword != nullptr)
			{
				hasWeapon = true;
				break;
			}
		}

		return hasWeapon;
	}
};


//#pragma once
//
//#include <string>
//#include "Entity.h"
//#include "Room.h"
//#include "Item.h"
//#include <vector>
//
//class Player : public Entity {
//private:
//	const Room* m_pCurrentRoom;
//	std::string m_name;
//
//	using Items = std::vector<Item*>;
//	Items m_items;
//
//public:
//	Player() {}
//	Player(const std::string& name) : m_name(name) {}
//
//	~Player() {}
//
//	Player(const Player& originalPlayer);
//	Player(Player&& tempPlayer) noexcept;
//
//	void SetName(const std::string& name);
//	void SetName(const std::string& forename, const std::string& surname);
//
//	void operator+=(const std::string& name);
//
//	const Player& operator=(const Player& player);
//
//	Player& operator=(Player&& tempPlayer) noexcept;
//
//	const std::string& GetName() const;
//
//	void SetCurrentRoom(const Room* pCurrentRoom);
//
//	Room* GetCurrentRoom() const;
//
//	void AddItem(const Item* item);
//	bool HasWeapon();
//
//};

//#pragma once
//
//#include <string>
//#include "Entity.h"
//#include "Room.h"
//#include "Item.h"
//#include <vector>
//
//class Player : public Entity {
//private:
//	const Room* m_pCurrentRoom;
//	std::string m_name;
//
//	using Items = std::vector<Item*>;
//	Items m_items;
//
//public:
//	Player() {}
//	Player(const std::string& name) : m_name(name) {}
//
//	~Player() {}
//
//	Player(const Player& originalPlayer);
//	Player(Player&& tempPlayer) noexcept;
//
//	void SetName(const std::string& name);
//	void SetName(const std::string& forename, const std::string& surname);
//
//	void operator+=(const std::string& name);
//
//	const Player& operator=(const Player& player);
//
//	Player& operator=(Player&& tempPlayer) noexcept;
//
//	const std::string& GetName() const;
//
//	void SetCurrentRoom(const Room* pCurrentRoom);
//
//	Room* GetCurrentRoom() const;
//
//	void AddItem(const Item* item);
//	bool HasWeapon();
//
//};