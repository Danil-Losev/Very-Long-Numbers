#include "verylong.h"


using namespace vln;

int main()
{
	verylong a, b, c;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	c = a - b;
	std::cout << "a - b = " << c << std::endl;
	c = a * b;
	std::cout << "a * b = " << c << std::endl;
	c = a / b;
	std::cout << "a / b = " << c << std::endl;
	return 0;
}