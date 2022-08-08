#include "Chest.h"

Chest::Chest(const Item* item)
	: m_item{ item }
{

}

void Chest::Update()
{
	// nothing to do for a chest
}

//#include "Chest.h"
//#include <iostream>
//
//Chest::Chest(const Item* item)
//	: m_item{ item }
//{
//
//}
//
//void Chest::Update() {
//	// does nothing
//}
//
//bool Chest::IsOpen() const {
//	return m_isOpen;
//}
//
//const Item* Chest::Open() {
//	m_isOpen = true;
//	return m_item;
//}
