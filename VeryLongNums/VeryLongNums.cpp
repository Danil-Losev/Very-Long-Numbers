// VeryLongNums.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "verylong.h"

using namespace vln;

int main()
{
	
	verylong a = verylong("123123123123");
	verylong b = verylong("123123123123");
	verylong c = a + b;
	std::cout << c << std::endl;
	c = a - b;
	std::cout << c << std::endl;
	c = a * b;
	std::cout << c << std::endl;

}