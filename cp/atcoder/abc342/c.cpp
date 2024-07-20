#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n{};
    cin >> n;
    string str{};
    cin >> str;

    map<char, char> m1{};
    map<char, set<char>> m2{};

    int q{};
    cin >> q;

    while (q--)
    {
        char x{}, y{};
        cin >> x >> y;

        if (m2.count(x) > 0)
        {
            for (char chr : m2[x])
            {
                m1[chr] = y;
                m2[y].insert(chr);
            }
            m2[x].clear();
            if(!m1.count(x))
                m1[x] = y;
        }
        else
        {
            m1[x] = y;
            m2[y].insert(x);
        }
    }

    for (char x : str)
    {
        if (m1.count(x) > 0)
            cout << m1[x];
        else
            cout << x;
    }
    cout << '\n';

    return 0;
}