#include <iostream>
#include "extern.h"

void NormalLocalVariable() {
	int x = 0;
	std::cout << x++ << "\n";
}

void StaticLocalVariable() {
	static int x = 0;
	std::cout << x++ << "\n";
}

class StaticCounter {
private:
	static int m_counter;

public:
	void IncrementCounter() { ++m_counter; }

	void Print() { std::cout << m_counter << "\n"; }
};

class StaticCounterMethod {
private:
	static int m_counter;

public:
	static void IncrementCounter() { ++m_counter; }

	static void Print() { std::cout << m_counter << "\n"; }
};

int StaticCounter::m_counter = 0;
int StaticCounterMethod::m_counter = 0;


int globalVariable = 0;
int fileVariable = 0;

namespace {
	const unsigned int MAX_LOOPS = 10;
}


class ConstantExample
{
	friend class ConstantExampleFriend;
private:
	int m_counter;
	mutable int m_countGets;

	int GetCounter() const;
public:
	ConstantExample() : m_counter(0), m_countGets(0) {}
	int GetCounter() const;
	void IncrementCounter();
};

inline int ConstantExample::GetCounter() const
{
	++m_countGets;
	return m_counter;
}

inline void ConstantExample::IncrementCounter()
{
	++m_counter;
}

class ConstantExampleFriend {
public:
	int GetCounter(const ConstantExample& constantExample) {
		return constantExample.GetCounter();
	}
};


int main() {
	// Static local variable
	std::cout << "Run NormalLocalVariable 10 times: \n";
	for (int i = 0; i < 10; i++) {
		NormalLocalVariable();
	}

	std::cout << "Run StaticLocalVariable 10 times: \n";
	for (int i = 0; i < 10; i++) {
		StaticLocalVariable();
	}

	// Static class member variable
	std::cout << "\nDefine two instances of StaticCounter classes and run member functions: \n";
	StaticCounter counter1;
	counter1.Print();
	counter1.IncrementCounter();
	counter1.Print();

	StaticCounter counter2;
	counter2.Print();
	counter2.IncrementCounter();
	counter2.Print();

	// Static member methods
	std::cout << "\nStatic member methods\n";
	StaticCounterMethod::Print();
	StaticCounterMethod::IncrementCounter();
	StaticCounterMethod::Print();
	StaticCounterMethod::Print();
	StaticCounterMethod::IncrementCounter();
	StaticCounterMethod::Print();

	// Static to alter global scope
	std::cout << "\nStatic to alter global scope\n";
	IncrementGlobalCounters();
	std::cout << globalVariable << std::endl;

	// Constant variables
	std::cout << "\nConstant variables\n";
	unsigned int arrayOfValues[MAX_LOOPS];
	for (unsigned int i = 0; i < MAX_LOOPS; ++i)
	{
		IncrementGlobalCounters();
		std::cout << globalVariable << "\n";
		std::cout << fileVariable << "\n";
	}	

	// Constant pointers
	const char* const NAME = "Bruce Sutherland";
	const char* BOOK = "Learn C++ Game Development";
	char YEAR[5] = "2014";
	char* const p = YEAR;
	p[0] = '3';

	std::cout << YEAR << "\n";



	// Constant member methods

	// Inline keyword
	ConstantExample example;
	const ConstantExample& constRefExample = example;
	//int count = constRefExample.GetCounter(); Not working when private

	// friend keyword
	ConstantExample example;
	ConstantExampleFriend exampleFriend;
	int count = exampleFriend.GetCounter(example);

	return 0;
}