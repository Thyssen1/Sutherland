/*
#include <iostream>

// Base class
class Vehicle {
protected:
	unsigned int m_numberOfWheels;

public:
	Vehicle();
	~Vehicle();

	unsigned int GetNumberOfWheels() const;
};

Vehicle::Vehicle() : m_numberOfWheels(0) {
	std::cout << "Vehicle created!\n";
}

Vehicle::~Vehicle() {
	std::cout << "Vehicle destroyed!\n";
}

unsigned int Vehicle::GetNumberOfWheels() const { return m_numberOfWheels; }
unsigned int Vehicle::GetNumberOfWheels() const { return 0; }

// Derived class
class Car : public Vehicle {
public:
	Car();
	~Car();
};

Car::Car() {
	m_numberOfWheels = 4;

	std::cout << "Car created!\n";
}

Car::~Car() {
	std::cout << "Car destroyed!\n";
}


class Motorcycle : public Vehicle {
public:
	Motorcycle();
	~Motorcycle();
};

Motorcycle::Motorcycle() {
	m_numberOfWheels = 2;
	
	std::cout << "Motorcycle created!\n";
}

Motorcycle::~Motorcycle() {
	std::cout << "Motorcycle destroyed!\n";
}

void PrintNumberOfWheels() {
	Vehicle vehicle;
	Car car;
	Motorcycle motorcycle;

	std::cout << vehicle.GetNumberOfWheels() << "\n";
	std::cout << car.GetNumberOfWheels() << "\n";
	std::cout << motorcycle.GetNumberOfWheels() << "\n";
}


int main() {
	PrintNumberOfWheels();


	return 0;
}
*/