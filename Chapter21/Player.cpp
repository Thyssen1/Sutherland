//#include "Player.h"
//
//void Player::AddItem(const Item* item) {
//	m_items.push_back(const_cast<Item*>(item));
//}
//
//bool Player::HasWeapon()
//{
//	bool hasWeapon = false;
//
//	for (const Item* item : m_items)
//	{
//		const Sword* sword = dynamic_cast<const Sword*>(item);
//		if (sword != nullptr)
//		{
//			hasWeapon = true;
//			break;
//		}
//	}
//
//	return hasWeapon;
//}
//
//Player::Player(const Player& originalPlayer) {
//	m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
//	m_name = originalPlayer.m_name;
//}
//
//Player::Player(Player&& tempPlayer) noexcept {
//	m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
//	m_name = tempPlayer.m_name;
//}
//
//void Player::SetName(const std::string& name) {
//	m_name = name;
//}
//
//void Player::SetName(const std::string& forename, const std::string& surname) {
//	m_name = forename;
//	m_name.append(" ");
//	m_name.append(surname);
//}
//
//void Player::operator+=(const std::string& name) {
//	m_name.append(name);
//}
//
//Player& Player::operator=(Player&& tempPlayer) noexcept {
//	if (this != &tempPlayer) {
//		m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
//		m_name = tempPlayer.m_name;
//
//		tempPlayer.m_pCurrentRoom = nullptr;
//		m_name.clear();
//	}
//
//	return *this;
//}
//
//
//const Player& Player::operator=(const Player& originalPlayer) {
//	m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
//	m_name = originalPlayer.m_name;
//	return *this;
//}
//
//const std::string& Player::GetName() const {
//	return m_name;
//}
//
//void Player::SetCurrentRoom(const Room* pCurrentRoom) {
//	m_pCurrentRoom = pCurrentRoom;
//}
//
//Room* Player::GetCurrentRoom() const {
//	return m_pCurrentRoom;
//}