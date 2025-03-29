#include "verylong.h"

vln::verylong::verylong()
{
	veryLongString = new char[SIZE];
	veryLongSize = 1;
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

vln::verylong::verylong(const unsigned long long input)
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

char* vln::verylong::getVeryLongString()
{
	char* charVeryLongString = new char[veryLongSize + 1];
	for (int i = SIZE - veryLongSize; i < SIZE; i++)
	{
		charVeryLongString[i - SIZE + veryLongSize] = veryLongString[i];
	}
	charVeryLongString[veryLongSize] = '\0';
	return charVeryLongString;
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

bool vln::verylong::operator!() const
{
	if (veryLongSize == 1 && veryLongString[SIZE - 1] == '0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

vln::verylong vln::verylong::operator+(const unsigned long long input) const
{
	return *this + vln::verylong(input);
}

vln::verylong vln::verylong::operator-(const unsigned long long input) const
{
	return *this - vln::verylong(input);
}

vln::verylong vln::verylong::operator+(const vln::verylong& input) const
{
	vln::verylong result;
	int carry = 0;
	int resultSize = veryLongSize > input.veryLongSize ? veryLongSize : input.veryLongSize;
	int firstSize = veryLongSize;
	int secondSize = input.veryLongSize;
	int sum = 0;
	for (int i = SIZE - 1; i >= SIZE - resultSize; i--)
	{
		if (firstSize > 0)
		{
			sum += (int)(veryLongString[i] - '0');
			firstSize--;
		}
		if (secondSize > 0)
		{
			sum += (int)(input.veryLongString[i] - '0');
			secondSize--;
		}
		sum += carry;
		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		else
		{
			carry = 0;
		}
		result.veryLongString[i] = sum + '0';
		sum = 0;
	}
	if (carry == 1)
	{
		result.veryLongString[SIZE - resultSize - 1] = '1';
		result.veryLongSize = resultSize + 1;
	}
	else
	{
		result.veryLongSize = resultSize;
	}
	return result;
}

vln::verylong vln::verylong::operator-(const vln::verylong& input) const
{
	if (*this < input)
	{
		std::cout << "Error! The first number must be greater than the second!" << std::endl;
		return vln::verylong();
	}
	vln::verylong result;
	int resultSize = veryLongSize > input.veryLongSize ? veryLongSize : input.veryLongSize;
	int firstSize = veryLongSize;
	int secondSize = input.veryLongSize;
	int difference = 0;
	int borrow = 0;
	for (int i = SIZE - 1; i >= SIZE - resultSize; i--)
	{
		if (firstSize > 0)
		{
			difference += (int)(veryLongString[i] - '0');
			firstSize--;
		}
		if (secondSize > 0)
		{
			difference -= (int)(input.veryLongString[i] - '0');
			secondSize--;
		}
		difference -= borrow;
		if (difference < 0)
		{
			borrow = 1;
			difference += 10;
		}
		else
		{
			borrow = 0;
		}
		result.veryLongString[i] = difference + '0';
		difference = 0;
	}
	for (int i = SIZE - resultSize; i < SIZE - 1; i++)
	{
		if (result.veryLongString[i] - '0' == 0)
		{
			resultSize--;
		}
		else
		{
			break;
		}
	}

	result.veryLongSize = resultSize;
	return result;
}


vln::verylong vln::verylong::operator*(const vln::verylong& input) const
{
	vln::verylong result;
	int carry = 0;
	int resultSize = veryLongSize + input.veryLongSize;
	for (int i = 0; i < resultSize; i++)
	{
		result.veryLongString[SIZE - 1 - i] = '0';
	}
	for (int i = 0; i < veryLongSize; i++)
	{
		carry = 0;
		for (int j = 0; j < input.veryLongSize; j++)
		{
			int temp = (veryLongString[SIZE - 1 - i] - '0') * (input.veryLongString[SIZE - 1 - j] - '0') + (result.veryLongString[SIZE - 1 - (i + j)] - '0') + carry;
			carry = temp / 10;
			result.veryLongString[SIZE - 1 - (i + j)] = (temp % 10) + '0';
		}
		result.veryLongString[SIZE - 1 - (i + input.veryLongSize)] += carry;
	}
	while (resultSize > 1 && result.veryLongString[SIZE - resultSize] == '0')
	{
		resultSize--;
	}
	result.veryLongSize = resultSize;
	return result;
}

vln::verylong vln::verylong::operator/(const vln::verylong& input) const // TODO: Fix division and add remainder
{
	if (*this == 0) return vln::verylong();
	if (input == 0)
	{
		std::cout << "Error! Division by zero!" << std::endl;
		return vln::verylong();
	}
	vln::verylong result;
	vln::verylong temp = *this;
	vln::verylong temp2 = input;
	int resultSize = 0;
	while (temp >= temp2)
	{
		temp = temp - temp2;
		resultSize++;
	}
	result = (verylong)resultSize;
	return result;
}

vln::verylong vln::verylong::operator=(const vln::verylong& input)
{
	if (this == &input)
	{
		return *this;
	}
	delete[] veryLongString;
	veryLongString = new char[SIZE];
	veryLongSize = input.veryLongSize;
	for (int i = SIZE - veryLongSize; i < SIZE; i++)
	{
		veryLongString[i] = input.veryLongString[i];
	}
	return *this;
}

vln::verylong vln::verylong::operator=(const unsigned long long input)
{
	delete[] veryLongString;
	veryLongString = new char[SIZE];
	char temp[SIZE];
	_ultoa_s(input, temp, 10);
	int tempSize = strlen(temp);
	veryLongSize = tempSize;
	for (int i = 0; i < tempSize; i++)
	{
		veryLongString[SIZE - tempSize + i] = temp[i];
	}
	return *this;
}

vln::verylong vln::verylong::operator++()
{
	*this = *this + (verylong)1;
	return *this;
}

vln::verylong vln::verylong::operator++(int)
{
	vln::verylong temp = *this;
	*this = *this + (verylong)1;
	return temp;
}

vln::verylong vln::verylong::operator--()
{
	*this = *this - (verylong)1;
	return *this;
}

vln::verylong vln::verylong::operator--(int)
{
	vln::verylong temp = *this;
	*this = *this - (verylong)1;
	return temp;
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

const vln::verylong vln::verylong::getFactorial(int input)
{
	return input > 0 ? (getFactorial(input - 1) * (verylong)input) : (verylong)1;
}

long long vln::verylong::getByteSize()
{
	return SIZE * sizeof(char) + sizeof(int) + sizeof(char*) + sizeof(const int);
}

vln::verylong::operator unsigned long long() const
{
	if (veryLongSize > 10)
	{
		std::cout << "Error! The number is too big!" << std::endl;
		return 0;
	}
	long long result = 0;
	for (int i = SIZE - veryLongSize; i < SIZE; i++)
	{
		result = result * 10 + (veryLongString[i] - '0');
	}
	return result;
}

vln::verylong::operator char* () const
{
	char* charVeryLongString = new char[veryLongSize + 1];
	for (int i = SIZE - veryLongSize; i < SIZE; i++)
	{
		charVeryLongString[i - SIZE + veryLongSize] = veryLongString[i];
	}
	charVeryLongString[veryLongSize] = '\0';
	return charVeryLongString;
}

vln::verylong::~verylong()
{
	delete[] veryLongString;
}
