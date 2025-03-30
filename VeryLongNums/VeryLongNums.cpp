#include "verylong.h"
#include "longint.h"

using namespace vln;

int main()
{
	longint a(1234567890);
	std::cin >> a;
	std::cout << a << std::endl;
	std::cout << a.getByteSize() << std::endl;
	std::cout << a.getSize() << std::endl;
	std::cout << a.getString() << std::endl;
	std::cout << (long long)a << std::endl;
	std::cout << (char*)a << std::endl;
	return 0;
}