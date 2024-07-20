#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int max_n{static_cast<int>(4e5 + 1)};

vector<int> adj[max_n];
bitset<max_n> visited{};
int prevArr[max_n];
int height[max_n];

void reset(int n)
{
    for(int i{}; i <= n; ++i) {
        adj[i].clear();
        prevArr[i] = -1;
        height[i] = 0;
    }   
}

int bfs(int node, int type = 0)
{
    queue<int> q{};
    int res{node};
    q.push(res);

    visited[node] = true;
    if (type == 1)
        prevArr[node] = -1;
    while (!q.empty())
    {
        res = q.front();
        q.pop();

        for (int e : adj[res])
        {
            if (visited[e])
                continue;

            q.push(e);
            if (type == 1)
                prevArr[e] = res;

            visited[e] = true;
        }
    }

    return res;
}

int dfs(int curr, int prev)
{
    int res{0};

    for (int node : adj[curr])
    {
        if (node == prev)
            continue;
        res = max(res, dfs(node, curr) + 1);
    }

    return height[curr] = res;
}

void solve()
{
    int n{}, k{};
    cin >> n >> k;
    reset(n);

    for (int i{}; i < n - 1; ++i)
    {
        int x{}, y{};
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visited.reset();
    int far{bfs(1)};
    visited.reset();
    int far2{bfs(far, 1)};

    vector<int> path{far2};
    while (prevArr[far2] != -1)
    {
        far2 = prevArr[far2];
        path.push_back(far2);
    }

    int c1{path[path.size() / 2]},
        c2{path.size() % 2 == 0 ? path[path.size() / 2 - 1] : -1};

    dfs(c1, c2);
    if(c2 != -1)
        dfs(c2, c1);
    
    ll res{};
    for(int i{1}; i <= n; ++i)
        if(height[i] >= k)
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