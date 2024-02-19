#include <bits/stdc++.h>
using namespace std;

constexpr int max_size{10001};

vector<vector<int>> city(max_size);
vector<bool> visited(max_size);

int dfs(int index) {
    if(visited[index])
        return index;

    if (city[index].size() == 0)
        return index;

    int res{};
    for (int neighbour : city[index]) {
        res = max(dfs(neighbour), res);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n{}, m{};
    cin >> n >> m;
    
    city.clear();
    visited.clear();

    for(;m--;) {
        int a{}, b{};
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    for(int i{}; i <= n; ++i) {
        for(int )
    }

    return 0;
}