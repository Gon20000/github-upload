#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll max_size{5000};
ll grid[max_size][max_size];
bool visited[max_size][max_size];
ll h{}, w{};
ll current_res{};

ll calculate(int x, int y, int left, int right, ll prev = 0)
{
    if (x >= h || x < 0 || y < left || y >= right || visited[x][y] || prev != grid[x][y])
        return 0;

    visited[x][y] = true;

    calculate(x, y + 1, left, right, grid[x][y]);
    calculate(x + 1, y, left, right, grid[x][y]);
    calculate(x, y - 1, left, right, grid[x][y]);
    calculate(x - 1, y, left, right, grid[x][y]);
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    ll res{INT_MAX};
    ll current_res{};

    for (int i{}; i < h; ++i)
    {
        for (int j{}; j < w; ++j)
        {
            cin >> grid[i][j];
        }
    }

    for (int i{1}; i < w; ++i)
    {
        memset(visited, 0, sizeof(visited));
        current_res = 0;

        for (int j{}; j < i; ++j)
        {
            for (int k{}; k < h; ++k)
            {

                current_res += calculate(k, j, 0, i, grid[k][j]);
            }
        }

        for (int j{i}; j < w; ++j)
        {
            for (int k{}; k < h; ++k)
            {

                current_res += calculate(k, j, i, w, grid[k][j]);
            }
        }

        res = min(res, current_res);
    }

    //    cout << current_res << '\n';

    cout << res << '\n';

    return 0;
}