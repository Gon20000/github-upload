#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll indegree[100001];
vector<int> adj[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(indegree, 0, sizeof indegree);

    int n{}, m{};
    cin >> n >> m;

    while(m--) {
        int x{}, y{};
        cin >> x >> y;

        adj[x].push_back(y);
        ++indegree[y];
    }

    vector<int> res{};
    queue<int> q{};
    for (size_t i{1}; i <= n; ++i)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int node{q.front()};
        q.pop();
        res.push_back(node);

        for(int child : adj[node]) {
            if(--indegree[child] == 0) 
                q.push(child);
        }
    }

    if(res.size() != n)
        cout << "IMPOSSIBLE\n";
    else {
        for(size_t i{}; i < n - 1; ++i) 
            cout << res[i] << ' ';

        cout << res[n - 1] << '\n';
    }

    return 0;
}