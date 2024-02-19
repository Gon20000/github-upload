#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll indegree[100001];
ll outdegree[100001];
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
    
    pair<int, ll> start{0, INT_MAX};
    for (size_t i{1}; i <= n; ++i)
    {
        if(indegree[i] < start.second)
            start = {i, indegree[i]};
    }

    q.push(start.first);
    bool found{false};
    while(!q.empty() && !found) {
        int node{q.front()};
        q.pop();
        res.push_back(node);

        for(int child : adj[node]) {
            if(child == start.first) {
                found = true;
                break;
            }
            if(--indegree[child] == 0) 
                q.push(child);
        }
    }

    if(!found)
        cout << "IMPOSSIBLE\n";
    else {
        res.push_back(start.first);

        cout << res.size() << '\n';
        for(size_t i{}; i < n - 1; ++i) 
            cout << res[i] << ' ';

        cout << res[n - 1] << '\n';
    }

    return 0;
}