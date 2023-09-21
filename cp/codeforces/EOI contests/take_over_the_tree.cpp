#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int max_size{300001};
bool visited[max_size];

int main() {
    int n{};
    cin >> n ;

    vector<map<ll, vector<ll>>> tree(n + 1); // vector [weight : [nodes]]
    memset(visited, 0, max_size);
    map<ll, pair<ll, ll>> path{}; // shortest path followed by prev node

    for (int i{0}; i < n - 1; ++i) {
        ll u{}, v{}, w{};
        cin >> u >> v >> w;
        
        tree[u].insert({w, {v}});
        tree[v].insert({w, {u}});
    }

    cout << -1 << '\n';

}