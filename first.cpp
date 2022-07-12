#include <cassert>
#include <cmath>
#include <iostream>

class FixedPoint2
{
private:
	std::int16_t m_base{};
	std::int8_t m_decimalPart{};

public:
	explicit FixedPoint2(double number)
		: m_base{static_cast<std::int16_t>(std::round(number))},
		  m_decimalPart{static_cast<std::int8_t>(std::round((number - m_base) * 100))}
	{
	}
	explicit FixedPoint2(std::int16_t base = 0, std::int8_t decimalPart = 0)
		: m_base{base}, m_decimalPart{decimalPart}
	{
		assert((decimalPart > 99 || decimalPart < 99) &&
			   "The decimal part should be 2 digits or less");
		if (m_base < 0 || m_decimalPart < 0)
		{
			// Make sure base is negative
			if (m_base > 0)
				m_base = -m_base;
			// Make sure decimal is negative
			if (m_decimalPart > 0)
				m_decimalPart = -m_decimalPart;
		}
	}

	explicit operator double() const
	{
		return m_base + m_decimalPart / 100.0;
	}

	FixedPoint2 operator-() const {
		return FixedPoint2{-(operator double())};
	}

	friend bool operator==(const FixedPoint2 &first, const FixedPoint2 &second);
};

FixedPoint2 operator+(const FixedPoint2 &first, const FixedPoint2 &second)
{
	return FixedPoint2{static_cast<double>(first) + static_cast<double>(second)};
}

bool operator==(const FixedPoint2 &first, const FixedPoint2 &second)
{
	return first.m_base == second.m_base &&
		   first.m_decimalPart == second.m_decimalPart;
}

std::ostream &operator<<(std::ostream &out, const FixedPoint2 &point)
{
	out << static_cast<double>(point);
	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& point) {
	double input{};
	in >> input;
	point = FixedPoint2(input);

	return in;
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';	  // both positive, no decimal overflow
	std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';	  // both positive, with decimal overflow
	std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';  // second negative, no decimal overflow
	std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';  // second negative, possible decimal overflow
	std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';	  // first negative, no decimal overflow
	std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';	  // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a{-0.48};
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}