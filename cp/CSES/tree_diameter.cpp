#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tree_t = vector<vector<ll>>;

ll height(const tree_t& tree, vector<ll>& dist, size_t idx, ll prev) {
    if(dist[idx]) {
        return dist[idx];
    }

    for(ll node : tree[idx]) {
        if(node == prev)
            continue;
        
        dist[idx] = max(dist[idx], height(tree, dist, node, idx) + 1);
    }

    return dist[idx];
}

ll maxLength(const tree_t& tree, vector<ll>& dist, size_t idx, ll prev) {

    ll ans{}, i{};
    priority_queue<ll> q{};

    // current node is in the path
    for(ll node : tree[idx]) {
        if(prev == node)
            continue;
        
        q.push(height(tree, dist, node, idx) + 1);
    }

    while(i < 2 && !q.empty()) {
        ans += q.top();
        q.pop();
        ++i;
    }

    // current node isn't in the path
    for(ll node : tree[idx]) {
        if(prev == node) 
            continue;

        ans =  max(ans, maxLength(tree, dist, node, idx)); 
    }

    return ans;
}

int main() { 
    size_t n{};
    cin >> n;

    if(n == 1)  {
        cout << 0;
        return 0;
    }

    tree_t tree(n + 1);
    vector<ll> dist(n + 1);

    for(int i{1}; i < n; ++i) {
        ll x{}, y{};
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    cout << maxLength(tree, dist, 1, 0) << '\n';

    return 0;
}