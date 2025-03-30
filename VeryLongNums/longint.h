

#if !defined(__LONGINT_H__)
#define __LONGINT_H__

#include <iostream>

class longint
{
private:
	char* string;
	int size;
	bool isNegative;
public:
	
	longint();
	longint(const longint& input);
	longint(const unsigned long long input, bool negative = false);
	longint(const char* input, bool negative = false);

	int getByteSize();
	int getSize();
	char* getString();
	
	char& operator[](int index);

	bool operator==(const longint& input)const;
	bool operator!=(const longint& input)const;
	bool operator<(const longint& input)const;
	bool operator>(const longint& input)const;
	bool operator<=(const longint& input)const;
	bool operator>=(const longint& input)const;
	bool operator!()const;
	
	longint operator+(const longint& input)const;
	longint operator-(const longint& input)const;
	longint operator*(const longint& input)const;
	longint operator/(const longint& input)const;
	longint operator=(const longint& input);
	
	
	longint operator++();
	longint operator++(int);
	longint operator--();
	longint operator--(int);
	
	friend std::istream& operator>>(std::istream& in, longint& input);
	friend std::ostream& operator<<(std::ostream& out, const longint& input);
	
	static const longint getFactorial(int input);
	
	
	operator long long()const;
	operator char* ()const;

	~longint();
};

#endif // __LONGINT_H__