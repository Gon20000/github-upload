#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr size_t max_n{250001};
bitset<max_n> done{};
vector<bitset<max_n>> children{};
map<int, set<int>> adj{};
bitset<max_n> visited{};

void init(int n) {
    for(int i{1}; i < n; ++i) {
        children[i].set(i);
    }
}

void dfs_util(size_t curr, size_t parent, bitset<max_n>& visited) {
    children[parent] |= children[curr];
    if(visited[curr] || done[curr]) {
        return;
    }

    visited[curr] = true;

    bool check{true};
    for(int child : adj[curr]) {
        children[curr] |= children[child];
        if(done[child]) {
            children[parent] |= children[child];
        }
        else {
            dfs_util(child, parent, visited);
            check = false;
        }
    }

    if(check)
        done[curr] = true;
}

void dfs(int parent) {
    visited.reset();

    for(int child : adj[parent])
        dfs_util(child, parent, visited);
    
    done[parent] = true;
}

void solve(int parent) {
    dfs(parent);
    for(int child : adj[parent]) {
        if(!done[child])
            solve(child);
    }
}

int main() {
    int n{}, k{};
    cin >> n >> k;
    vector<int> query(n);
    children.resize(k + 1);
    
    for(int i{}; i < n; ++i) 
        cin >> query[i];
    
    int m{};
    cin >> m;
    while(m--) {
        int x{}, y{};
        cin >> x >> y;

        adj[x].insert(y);
    }
    init(k + 1);
    
    solve(query[0]);

    int curr{query[0]}, res{2};
    for(int i{1}; i < n; ++i) {
        if(adj[curr].count(query[i]) > 0)
            res += 2;
        else if(children[curr][query[i]])
            ++res;
        else
            break;

        curr = query[i];
    }

    cout << res << '\n';

    return 0;
}