#include <cassert>
#include <cmath>


// Create a Template class
template<typename T>
class Template {
private:
	T* m_ptr;

public:
	Template(T* ptr) : m_ptr{ ptr } {}
};

// Two scenarios where const and constexpr will yield different results
const double constValue = sin(0.5);
//constexpr double constexprValue = sin(0.5);	// Does not compile 
// Compiler cannot guarantee that the value sin(0.5) is a constant expression
// evaluated at compile time
constexpr double a = 0.5;	// works. Can be evalauted at compile time.

int main() {
	int value = 1;
	Template<int> pointer(&value);

	assert(2 == 3);	// False is passed to asssert. 

	return 0;
}

