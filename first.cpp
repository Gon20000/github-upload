#include <exception>
#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        if (denominator == 0)
        {
            throw std::runtime_error("Invalid denominator");
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction)
    {
        return out << fraction.m_numerator << '/' << fraction.m_denominator;
    }
};

int getInput() {
    int num{};
    std::cin >> num;

    return num;
}

int main() {
    std::cout << "Enter the numerator: ";
    int numerator{getInput()};

    std::cout << "Enter the denominator: ";
    int denominator{getInput()};

    try {
        const Fraction fraction{numerator, denominator};
        std::cout << fraction << '\n';
    }
    catch(const std::exception& exception) {
        std::cout << exception.what() << '\n';
    }

    return 0;
}