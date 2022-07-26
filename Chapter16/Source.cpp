#include <set>
#include <map>
#include <string>
#include <iostream>
#include "TreeNode.h"
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>

using MySet = std::set<int>;
using MyMap = std::map<int, std::string>;
using MyPair = std::pair<int, std::string>;

using MyUnorderedSet = std::unordered_set<int>;
using MyUnorderedMap = std::unordered_map<int, std::string>;


int main() {
	// STL set container
	MySet mySet = { 2,1,0 };
	mySet.emplace(4); // Faster than insert
	mySet.insert(3); // Slower why?

	// STL map container
	MyMap myMap = { {2, "Two"}, {3, "Three"}, {4, "Four"} };

	MyPair node{ 4, "Four" };
	myMap.insert(node);

	myMap.emplace(3, "Three");

	for (const auto& node : myMap) {
		std::cout << "First: " << node.first << " Second: " << node.second << "\n";
	}

	MyMap::iterator found = myMap.find(2);
	if (found != myMap.end()) {
		std::cout << "First: " << found->first << " Second: " << found->second << "\n";
	}

	// STL binary search tree


	// STL unordered set and unordered map
	MyUnorderedSet myUnorderedSet = { 2,1,0 };
	myUnorderedSet.emplace(3);
	myUnorderedSet.insert(4);

	MyUnorderedMap myUnorderedMap = { {2,"Two"}, {1, "One"}, {0, "Zero"} };
	myUnorderedMap.emplace(3, "Three");
	myUnorderedMap.insert(node);

	// Find the value 2 in the unordered set
	MyUnorderedSet::iterator found_set = find(myUnorderedSet.begin(), myUnorderedSet.end(), 2);
	if (found_set != myUnorderedSet.end())
	{
		std::cout << "Found : " << *found_set << "\n";
	}

	found_set = myUnorderedSet.find(2);
	if (found_set != myUnorderedSet.end()) {
		std::cout << "Found: " << *found_set << "\n";
	}

	std::string& myString = myUnorderedMap[2];
	std::cout << "Found: " << myString << "\n";

	myString = myUnorderedMap.at(2);
	std::cout << "Found: " << myString << "\n";

	// Handling exceptions
	try {
		std::string& myString = myUnorderedMap.at(5);
		std::cout << "Found: " << myString << "\n";
	}
	catch (const std::out_of_range& outOfRange) {
		std::cout << "Out of range error: " << outOfRange.what() << "\n";
	}



	return 0;
}