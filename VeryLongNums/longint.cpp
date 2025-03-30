#include "longint.h"

longint::longint()
{
	string = new char[1];
	size = 1;
	string[0] = '0';
	isNegative = false;
}

longint::longint(const longint& input)
{
	string = new char[input.size];
	size = input.size;
	isNegative = input.isNegative;
	for (int i = 0; i < size; i++)
	{
		string[i] = input.string[i];
	}
}

longint::longint(const unsigned long long input, bool negative)
{
	char* temp = new char[21];
	_ltoa_s(input, temp, 21, 10);
	size = strlen(temp);
	string = new char[size];
	for (int i = 0; i < size; i++)
	{
		string[i] = temp[i];
	}
	isNegative = negative;
}

longint::longint(const char* input, bool negative)
{
	size = strlen(input);
	string = new char[size];
	for (int i = 0; i < size; i++)
	{
		string[i] = input[i];
	}
	isNegative = negative;
}

int longint::getByteSize()
{
	return sizeof(char) * size + sizeof(longint);
}

int longint::getSize()
{
	return size;
}

char& longint::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		return string[size - 1];
	}
	return string[index];
}

char* longint::getString()
{
	if (isNegative)
	{
		char* charString = new char[size + 2];
		charString[0] = '-';
		for (int i = 0; i < size; i++)
		{
			charString[i + 1] = string[i];
		}
		charString[size + 1] = '\0';
		return charString;
	}
	char* charString = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		charString[i] = string[i];
	}
	charString[size] = '\0';
	return charString;
}

longint::operator long long() const
{
	if (size > 10)
	{
		std::cout << "Error! The number is too big!" << std::endl;
		return 0;
	}
	long long result = 0;
	for (int i = 0; i < size; i++)
	{
		result = result * 10 + (string[i] - '0');
	}
	return isNegative ? -result : result;
}

longint::operator char* () const
{
	if (isNegative)
	{
		char* charString = new char[size + 2];
		charString[0] = '-';
		for (int i = 0; i < size; i++)
		{
			charString[i + 1] = string[i];
		}
		charString[size + 1] = '\0';
		return charString;
	}
	char* charString = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		charString[i] = string[i];
	}
	charString[size] = '\0';
	return charString;
}

longint::~longint()
{
	delete[] string;
}

std::istream& operator>>(std::istream& in, longint& input)
{
	char* temp = new char[2000];
	bool isErorr = false;
	do
	{
		isErorr = false;
		in >> temp;
		if (temp[0] == '-')
		{
			input.isNegative = true;
			for (int i = 1; i < strlen(temp); i++)
			{
				if (!isdigit(temp[i]))
				{
					isErorr = true;
					std::cout << "Error! Please enter a number!" << std::endl;
					break;
				}
			}
		}
		else
		{
			input.isNegative = false;
			for (int i = 0; i < strlen(temp); i++)
			{
				if (!isdigit(temp[i]))
				{
					isErorr = true;
					std::cout << "Error! Please enter a number!" << std::endl;
					break;
				}
			}
		}
	} while (isErorr);
	delete[] input.string;

	if (input.isNegative)
	{
		input.size = strlen(temp) - 1;
		input.string = new char[input.size];
		for (int i = 1; i < strlen(temp); i++)
		{
			input.string[i - 1] = temp[i];
		}
	}
	else
	{
		input.size = strlen(temp);
		input.string = new char[input.size];
		for (int i = 0; i < strlen(temp); i++)
		{
			input.string[i] = temp[i];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const longint& input)
{
	if (input.isNegative)
	{
		out << '-';
	}
	for (int i = 0; i < input.size; i++)
	{
		out << input.string[i];
	}
	return out;
}
