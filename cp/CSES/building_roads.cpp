#include <bits/stdc++.h>
using namespace std;

constexpr int max_size{100001};

vector<bool> visited(max_size);

void dfs(int index, const vector<vector<int>>& city) {
    if(visited[index])
        return;

    visited[index] = true;

    for (int neighbour : city[index]) {
        dfs(neighbour, city);
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n{}, m{};
    cin >> n >> m;
    
    vector<string> res{};
    vector<vector<int>> city(n+1);
    for (int i{}; i < n; ++i)
        visited[i] = false;

    for(;m--;) {
        int a{}, b{};
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    if (n > 1 && city[1].size() == 0) {
        city[1].push_back(2);
        city[2].push_back(1);
        res.push_back("1 2\n");
    }

    dfs(1, city);

    for(int i{1}; i <= n; ++i) {
        if (!visited[i]) {
            res.push_back(to_string(i - 1) + ' ' + to_string(i) + '\n');
            dfs(i, city);
        }
    }

    cout << res.size() << '\n';
    for(const string& road : res) {
        cout << road;
    }

    return 0;
}