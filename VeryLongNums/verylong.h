#if !defined(__VERYLONG_H__)
#define __VERYLONG_H__

#include <iostream>

/*
	* This class is a very long number class that can store numbers up to SIZE digits.
	* This class not working with negative numbers.
	* This class can be used with long long numbers.
	* This class is not very optimized because it uses a lot of memory.
	* Division is not working correctly ( it is working by minus operation) and there is no remainder 
	* ALLERT: Division algorithm is very slow and not optimized.
*/


// TODO: Add support of negative numbers and fix division 
namespace vln {
	class verylong
	{
	private:
		static const int SIZE = 1000;
		char* veryLongString;
		int veryLongSize;
	public:
		verylong();
		verylong(const vln::verylong& input);
		verylong(const unsigned long long input);
		verylong(const char* input);

		char& operator[](int index);
		char* getVeryLongString();

		bool operator==(const vln::verylong& input)const;
		bool operator!=(const vln::verylong& input)const;
		bool operator<(const vln::verylong& input)const;
		bool operator>(const vln::verylong& input)const;
		bool operator<=(const vln::verylong& input)const;
		bool operator>=(const vln::verylong& input)const;
		bool operator!()const;

		vln::verylong operator+(const unsigned long long input) const;
		vln::verylong operator-(const unsigned long long input) const;

		vln::verylong operator+(const vln::verylong& input)const;
		vln::verylong operator-(const vln::verylong& input)const;
		vln::verylong operator*(const vln::verylong& input)const;
		vln::verylong operator/(const vln::verylong& input)const;

		vln::verylong operator=(const vln::verylong& input);
		vln::verylong operator=(const unsigned long long input);
		
		vln::verylong operator++();
		vln::verylong operator++(int);
		vln::verylong operator--();
		vln::verylong operator--(int);

		friend std::istream& operator>>(std::istream& in, vln::verylong& input);
		friend std::ostream& operator<<(std::ostream& out, const vln::verylong& input);

		static const int getMaxSize();
		static const vln::verylong getFactorial(int input);
		static long long getByteSize();

		operator unsigned long long()const;
		operator char* ()const;


		~verylong();
	};
}
#endif // __VERYLONG_H__

