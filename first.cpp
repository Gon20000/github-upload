#include <iostream>
#include <string>

template <typename T>
class Pair1
{
private:
    T m_first{};
    T m_second{};

public:
    Pair1(const T &first, const T &second) : m_first{first}, m_second{second}
    {
    }

    const T &first() const { return m_first; }
    const T &second() const { return m_second; }
};

template <typename T1, typename T2>
class Pair
{
private:
    T1 m_first{};
    T2 m_second{};

public:
    Pair(const T1 &first, const T2 &second) : m_first{first}, m_second{second}
    {
    }

    const T1 &first() const { return m_first; }
    const T2 &second() const { return m_second; }
};

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(const std::string &first, const T& second)
        : Pair<std::string, T>(first, second) {}
};

int main()
{
    StringValuePair<int> svp{"Hello", 5};
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}