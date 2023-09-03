#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

class StackOfStacks
{
private:
    std::set<std::size_t> m_empty{0};
    std::set<std::size_t> m_mid{};
    std::set<std::size_t> m_full{};
    std::vector<std::stack<int>> m_arr{ std::stack<int>{}};
    std::size_t m_cap{};

public:
    StackOfStacks(int capacity)
    {
        m_cap = static_cast<std::size_t>(capacity);
    }

    void push(int val)
    {

        std::size_t top{INT16_MAX};
        bool inEmpty{true};
        if(!m_empty.empty()) {
            top = *m_empty.begin();
        }
        if(!m_mid.empty() && top > *m_mid.begin()) {
            inEmpty = false;
            top = *m_mid.begin();
        }

        m_arr[top].push(val);
        
        if(inEmpty) {
            m_empty.erase(top);
        }
        if()
    }

    int pop()
    {
        if (m_arr.empty())
        {
            return -1;
        }

        std::size_t back{};
        if (m_empty.empty())
        {
            back = m_arr.size() - 1;
        }
        else
        {
            back = *m_empty.rbegin();
        }

        if (m_arr[back].empty())
        {
            return -1;
        }
        int res{m_arr[back].top()};
        m_arr[back].pop();
        std::cout << m_arr[back].size() << '\n';

        if (m_arr[back].empty())
        {
            m_empty.insert(back);
        }

        return res;
    }

    int popStack(int idx)
    {
        std::size_t index{static_cast<std::size_t>(idx)};
        if (m_arr.empty() || m_arr.size() <= index || m_arr[index].empty())
        {
            return -1;
        }

        int res{m_arr[index].top()};
        m_arr[index].pop();

        if (m_arr[index].empty())
        {
            m_empty.insert(index);
        }

        return res;
    }
    friend std::ostream &operator<<(std::ostream &out, const StackOfStacks &s)
    {
        for (const auto &x : s.m_arr)
        {
            out << x.size() << ' ';
        }
        return out;
    }
};

int main()
{
    StackOfStacks s{1};
    s.push(0);
    s.push(1);
    std::cout << s << '\n';
    s.pop();
    std::cout << s.pop() << '\n';

}