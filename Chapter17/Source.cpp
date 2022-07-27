#include <stack>
#include <queue>
#include <iostream>


using MyStack = std::stack<int>;
using MyQueue = std::queue<int>;

int main() {
	// Stack data structure
	MyStack myStack;
	myStack.emplace(0);
	myStack.push(1);
	myStack.push(2);

	std::cout << myStack.top() << "\n";
	myStack.pop();
	std::cout << myStack.top() << "\n";

	// Queue data structure
	MyQueue myQueue;
	myQueue.emplace(0);
	myQueue.emplace(1);
	myQueue.emplace(2);

	std::cout << myQueue.front() << "\n";
	myQueue.pop();
	std::cout << myQueue.front() << "\n";

	return 0;
}