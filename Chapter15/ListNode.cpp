#include "ListNode.h"
#include <iostream>

void* ListNode::GetData() {
	return m_Data;
}

void ListNode::SetLast(ListNode* last) {
	m_Last = last;
}

ListNode* ListNode::GetLast() {
	return m_Last;
}

void ListNode::SetNext(ListNode* next) {
	m_Next = next;
}

ListNode* ListNode::GetNext() {
	return m_Next;
}

void OurList() {
	unsigned int firstData = 1;
	ListNode first(&firstData);

	unsigned int secondData = 2;
	ListNode second(&secondData);

	unsigned int thirdData = 3;
	ListNode third(&thirdData);

	first.SetNext(&second);

	second.SetLast(&first);
	second.SetNext(&third);

	third.SetLast(&second);

	for (ListNode* iter = &first; iter != nullptr; iter = iter->GetNext()) {
		unsigned int* number = static_cast<unsigned int*>(iter->GetData());
		std::cout << *number << "\n";
	}
}