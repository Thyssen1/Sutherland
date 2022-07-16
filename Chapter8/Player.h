#pragma once

#include <string>

class Player {
private:
	std::string m_name;

public:
	Player() {}
	Player(const std::string& name) : m_name(name) {}
	~Player() {}

	void SetName(const std::string& name) {
		m_name = name;
	}

	void SetName(const std::string& forename, const std::string& surname) {
		m_name = forename;
		m_name.append(" ");
		m_name.append(surname);
	}

	void operator+=(const std::string& name) {
		m_name.append(name);
	}

	const Player& operator=(const Player& player) {
		m_name = player.m_name;
		return *this;
	}

	const std::string& GetName() const {
		return m_name;
	}

};