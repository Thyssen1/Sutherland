#pragma once

class TreeNode {
private:
	int m_value;

	TreeNode* m_pLeft = nullptr;
	TreeNode* m_pRight = nullptr;

public:
	TreeNode(int value) : m_value{ value } {}

	TreeNode* Find(int searchValue);
};