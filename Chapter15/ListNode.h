// Basic implementation of doubly linked list
class ListNode {
private:
	void* m_Data = nullptr;
	ListNode* m_Last = nullptr;
	ListNode* m_Next = nullptr;

public:
	ListNode(void* data) : m_Data{ data } {}

	void* GetData();

	void SetLast(ListNode* last);
	ListNode* GetLast();

	void SetNext(ListNode* next);
	ListNode* GetNext();

};

void OurList();