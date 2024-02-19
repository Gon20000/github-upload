#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll max_size{500000};
bitset<max_size> grid{};

ll check(ll ind, ll n, ll m, vector<ll> cols)
{
    ll res{};

    for (ll i{}; i < m; ++i)
    {
        grid[ind * m + i].flip();
        cols[i] += (grid[ind * m + i] ? 1 : -1);
    }

    pair<ll, ll> maxCols{};

    for (ll i{}; i < m; ++i)
    {
        ll soFar{cols[i]};

        if (soFar > maxCols.first)
        {
            maxCols.first = soFar;
            maxCols.second = i;
        }
    }

    for (ll i{}; i < n * m; ++i) {
        if ((i - maxCols.second) % m == 0)
            res += !grid[i];
        else
            res += grid[i];

        if (i >= ind * m && i - (ind * m) < m) 
            grid[i].flip();
    }

    return res;
}

int main()
{
    ll n{}, m{};
    cin >> n >> m;

    ll res{};
    vector<ll> cols(m);

    for (ll i{}; i < n; ++i)
    {
        for (ll j{}; j < m; ++j)
        {
            char chr{};
            cin >> chr;
            if (chr == '0')
            {
                grid.set(i * m + j, false);
            }
            else
            {
                grid.set(i * m + j);
                ++cols[j];
            }
        }
    }

    for(int i{}; i < n; ++i) {
        res = max(res, check(i, n, m, cols));
    }

    cout << res << ' ' << n * m - res << '\n'; 
}