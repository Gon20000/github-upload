#include <bits/stdc++.h>
using namespace std;

const int max_size{1000};
bool grid[max_size][max_size];
int h{}, w{};

int calculate(int x, int y)
{
    if (x >= h || x < 0 || y < 0 || y >= w || !grid[x][y])
        return 0;

    grid[x][y] = false;

    calculate(x, y + 1);
    calculate(x + 1, y);
    calculate(x, y - 1);
    calculate(x - 1, y);
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    int res{};

    for (int i{}; i < h; ++i)
    {
        for (int j{}; j < w; ++j)
        {
            char x{};
            cin >> x;
            grid[i][j] = x == '.';
        }
    }

    for (int i{}; i < h; ++i)
    {
        for (int j{}; j < w; ++j)
        {
            res += calculate(i, j);
        }
    }

    cout << res << '\n';

    return 0;
}