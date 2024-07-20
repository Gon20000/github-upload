#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &x, pair<int, int> &y)
{
    return abs(x.second) < abs(y.second);
}

void solve()
{
    int n{}, k{};
    cin >> n >> k;

    vector<pair<int, int>> monsters(n);
    for (int i{}; i < n; ++i)
    {
        cin >> monsters[i].first;
    }
    for (int i{}; i < n; ++i)
    {
        cin >> monsters[i].second;
    }

    sort(monsters.begin(), monsters.end(), compare);

    int curr{0}, bul{k};
    for (pair<int, int> &x : monsters)
    {
        while (x.first > 0)
        {
            if (curr >= abs(x.second))
            {
                cout << "NO\n";
                return;
            }

            if (x.first <= bul)
            {
                bul -= x.first;
                x.first = 0;
            }
            else
            {
                x.first -= bul;
                bul = 0;
            }

            if (bul == 0)
            {
                ++curr;
                bul = k;
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    int t{};
    cin >> t;
    while (t--)
        solve();
}