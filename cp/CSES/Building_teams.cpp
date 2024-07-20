#include <bits/stdc++.h>
using namespace std;

constexpr int max_size{100001};

vector<int> teams(max_size);
vector<vector<int>> adj(max_size);
bitset<max_size> visited{};

bool bfs(int node)
{
    teams[node] = 1;
    visited[node] = true;

    queue<int> q{};
    q.push(node);

    while (!q.empty())
    {
        int curr{q.front()};
        q.pop();

        for (int child : adj[curr])
        {
            if (visited[child] && teams[child] == teams[curr])
            {
                return false;
            }
            else if (visited[child])
                continue;

            visited[child] = true;
            teams[child] = teams[curr] == 1 ? 2 : 1;
            q.push(child);
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin >> n >> m;

    for (int i{}; i <= n; ++i)
        teams[i] = 0;

    for (; m--;)
    {
        int a{}, b{};
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i{1}; i <= n; ++i)
    {
        if (!visited[i])
            if (!bfs(i))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
    }

    for (int i{1}; i < n; ++i)
        cout << teams[i] << ' ';
    cout << teams[n] << '\n';

    return 0;
}