#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tree_t = vector<vector<ll>>;

void dfs(const tree_t& tree, vector<ll>& count, int idx) {
    if(tree[idx].empty()) {
        return;
    }

    for(ll node : tree[idx]) {
        dfs(tree, count, node);
        count[idx] += count[node] + 1;
    }
}

int main() {
    size_t n{};
    cin >> n;

    tree_t tree(n + 1);
    vector<ll> cnt(n + 1);

    for(int i{2}; i <= n; ++i) {
        ll x{};
        cin >> x;

        tree[x].push_back(i);
    }

    dfs(tree, cnt, 1);
    for(int i{1}; i < n; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << cnt[n] << '\n';

    return 0;
}