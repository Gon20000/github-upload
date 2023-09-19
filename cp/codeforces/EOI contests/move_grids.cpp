#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a{}, res{};
    cin >> a;

    bitset<16> grid{static_cast<bitset<16>>(a)};

    for (int i{4}; i <= 15; ++i)
    {
        int j{i};

        while (j >= 4 && grid.test(j) && !grid.test(j - 4))
        {
            grid.flip(j);
            grid.flip(j - 4);

            j -= 4;
            ++res;
        }
    }

    for (int i{8}; i <= 15; ++i)
    {
        if (!grid.test(i))
            continue;

        pair<int, int> pos{400, 0};
        for (int j{}; j < 8; ++j)
        {
            if (!grid.test(j))
            {
                if (abs(i % 4 - j % 4) < pos.first)
                {
                    pos.first = abs(i % 4 - j % 4);
                    pos.second = j;
                }
            }
        }

        res += (i / 4 - pos.second / 4) + pos.first;
        grid.flip(pos.second);
        grid.flip(i);
    }

    cout << res << '\n';

    return 0;
}