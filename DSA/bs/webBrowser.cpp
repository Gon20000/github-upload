#include <bits/stdc++.h>

using namespace std;

class WebBrowser
{
public:
    std::vector<string> m_pages{};
    std::size_t m_current_page{};
    std::size_t m_max_pages{};

    WebBrowser(string homepage)
    {
        m_pages.push_back(std::move(homepage));
        ++m_max_pages;
    }

    void visit(string page)
    {
        if (m_max_pages == m_pages.size())
        {
            m_pages.push_back(std::move(page));
            m_max_pages = ++m_current_page + 1;
        }
        else
        {
            m_pages[++m_current_page] = std::move(page);
            m_max_pages = m_current_page + 1;
        }
    }

    string back(int n)
    {
        m_current_page = std::max(static_cast<int>(m_current_page) - n, 0);
        return m_pages[m_current_page];
    }

    string forward(int n)
    {
        if(m_current_page + n - 2 > m_max_pages - 1) {
            m_current_page = m_max_pages;
        }
        else {
            m_current_page = m_current_page + n - 1;
        }
        return m_pages[m_current_page];
    }
};

int main()
{
    WebBrowser x{"m.com"};
    std::cout << x.back(1) << '\n';
    std::cout << x.back(1) << '\n';
    x.visit("z.com");
    std::cout << x.forward(1) << '\n'; 
    x.visit("g.com");
    return 0;
}