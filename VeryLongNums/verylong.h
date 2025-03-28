#include <iostream>

#if !defined(__VERYLONG_H__)
#define __VERYLONG_H__

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
		verylong(const long long input);
		verylong(const char* input);

		char& operator[](int index);

		bool operator==(const vln::verylong& input)const;
		bool operator!=(const vln::verylong& input)const;
		bool operator<(const vln::verylong& input)const;
		bool operator>(const vln::verylong& input)const;
		bool operator<=(const vln::verylong& input)const;
		bool operator>=(const vln::verylong& input)const;

		vln::verylong operator+(const vln::verylong& input)const;
		vln::verylong operator-(const vln::verylong& input)const;
		vln::verylong operator*(const vln::verylong& input)const;
		vln::verylong operator/(const vln::verylong& input)const;

		friend std::istream& operator>>(std::istream& in, vln::verylong& input);
		friend std::ostream& operator<<(std::ostream& out, const vln::verylong& input);

		static const int getMaxSize();

		~verylong();
	};
}
#endif // __VERYLONG_H__

