#include "verylong.h"
#include <cstdlib>
#include <string.h>
#include <iostream>

vln::verylong::verylong()
{
	veryLongString = new char[SIZE];
	veryLongSize = 0;
	veryLongString[SIZE - 1] = '0';
}


vln::verylong::verylong(const vln::verylong& input)
{
	veryLongString = new char[SIZE];
	veryLongSize = input.veryLongSize;
	for (int i = SIZE - veryLongSize; i < SIZE; i++)
	{
		veryLongString[i] = input.veryLongString[i];
	}
}

vln::verylong::verylong(const long long input)
{
	veryLongString = new char[SIZE];
	char temp[SIZE];
	_itoa_s(static_cast<int>(input), temp, 10);
	int tempSize = strlen(temp);
	veryLongSize = tempSize;
	for (int i = 0; i < tempSize; i++)
	{
		veryLongString[SIZE - tempSize + i] = temp[i];
	}
}

vln::verylong::verylong(const char* input)
{
	veryLongString = new char[SIZE];
	int tempSize = strlen(input);
	veryLongSize = tempSize;
	for (int i = 0; i < tempSize; i++)
	{
		veryLongString[SIZE - tempSize + i] = input[i];
	}
}

char& vln::verylong::operator[](int index)
{
	return veryLongString[SIZE - veryLongSize + index];
}

bool vln::verylong::operator==(const vln::verylong& input) const
{
	bool isEqual = true;
	if (veryLongSize != input.veryLongSize)
	{
		isEqual = false;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] != input.veryLongString[i])
			{
				isEqual = false;
				break;
			}
		}
	}
	return isEqual;
}

bool vln::verylong::operator!=(const vln::verylong& input) const
{
	bool isNotEqual = false;
	if (veryLongSize != input.veryLongSize)
	{
		isNotEqual = true;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] != input.veryLongString[i])
			{
				isNotEqual = true;
				break;
			}
		}
	}
	return isNotEqual;
}

bool vln::verylong::operator<(const vln::verylong& input) const
{
	bool isLess = false;
	if (veryLongSize > input.veryLongSize)
	{
		isLess = false;
	}
	else if (veryLongSize < input.veryLongSize)
	{
		isLess = true;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] < input.veryLongString[i])
			{
				isLess = true;
				break;
			}
		}
	}
	return isLess;
}

bool vln::verylong::operator>(const vln::verylong& input) const
{
	bool isBigger = false;
	if (veryLongSize > input.veryLongSize)
	{
		isBigger = true;
	}
	else if (veryLongSize < input.veryLongSize)
	{
		isBigger = false;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] > input.veryLongString[i])
			{
				isBigger = true;
				break;
			}
		}
	}
	return isBigger;
}

bool vln::verylong::operator<=(const vln::verylong& input) const
{
	bool isLessOrEqual = false;
	if (*this == input)
	{
		isLessOrEqual = true;
	}
	else if (veryLongSize < input.veryLongSize)
	{
		isLessOrEqual = true;
	}
	else if (veryLongSize > input.veryLongSize)
	{
		isLessOrEqual = false;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] < input.veryLongString[i])
			{
				isLessOrEqual = true;
				break;
			}
		}
	}
	return isLessOrEqual;
}

bool vln::verylong::operator>=(const vln::verylong& input) const
{
	bool isBiggerOrEqual = false;
	if (*this == input)
	{
		isBiggerOrEqual = true;
	}
	else if (veryLongSize > input.veryLongSize)
	{
		isBiggerOrEqual = true;
	}
	else if (veryLongSize < input.veryLongSize)
	{
		isBiggerOrEqual = false;
	}
	else
	{
		for (int i = SIZE - veryLongSize; i < SIZE; i++)
		{
			if (veryLongString[i] > input.veryLongString[i])
			{
				isBiggerOrEqual = true;
				break;
			}
		}
	}
	return isBiggerOrEqual;
}

std::istream& vln::operator>>(std::istream& in, vln::verylong& input)
{
	char* temp = new char[input.SIZE];
	bool isErorr = false;
	do
	{
		isErorr = false;
		in >> temp;
		for (int i = 0; i < strlen(temp); i++)
		{
			if (!isdigit(temp[i]))
			{
				isErorr = true;
				std::cout << "Error! Please enter a number!" << std::endl;
				break;
			}
		}
	} while (isErorr);
	int tempSize = strlen(temp);
	input.veryLongSize = tempSize;
	for (int i = 0; i < tempSize; i++)
	{
		input.veryLongString[input.SIZE - tempSize + i] = temp[i];
	}
	delete[] temp;
	return in;
}

std::ostream& vln::operator<<(std::ostream& out, const vln::verylong& input)
{
	for (int i = input.SIZE - input.veryLongSize; i < input.SIZE; i++)
	{
		out << input.veryLongString[i];
	}
	return out;
}


const int vln::verylong::getMaxSize()
{
	return SIZE;
}

vln::verylong::~verylong()
{
	delete[] veryLongString;
}
