#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n{}, k{};
    cin >> n >> k;

    ++n;
    vector<int> adj[n], rem(n, 0), layer(n, 0);

    for (int i{1}; i < n - 1; ++i)
    {
        int x{}, y{};
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        ++rem[x];
        ++rem[y];
    }

    queue<int> q{};
    for (int i{1}; i < n; ++i)
        if (rem[i] == 1)
            q.push(i);

    while (!q.empty())
    {
        int curr{q.front()};
        q.pop();
        --rem[curr];

        for (int parent : adj[curr])
        {
            if (rem[parent] < 1)
                continue;

            --rem[parent];

            if (rem[parent] == 1)
            {
                q.push(parent);
                layer[parent] = layer[curr] + 1;
            }
        }
    }

    ll res{};
    for(int i{1}; i < n; ++i)
        if(layer[i] >= k)
            ++res;
    
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while (t--)
        solve();

    return 0;
}