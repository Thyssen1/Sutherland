#include "Player.h"

void Player::SetName(const std::string& name) {
	m_name = name;
}

void Player::SetName(const std::string& forename, const std::string& surname) {
	m_name = forename;
	m_name.append(" ");
	m_name.append(surname);
}

void Player::operator+=(const std::string& name) {
	m_name.append(name);
}

const Player& Player::operator=(const Player& player) {
	m_name = player.m_name;
	return *this;
}

const std::string& Player::GetName() const {
	return m_name;
}

void Player::SetCurrentRoom(const Room* pCurrentRoom) {
	m_pCurrentRoom = pCurrentRoom;
}

const Room* Player::GetCurrentRoom() const {
	return m_pCurrentRoom;
}