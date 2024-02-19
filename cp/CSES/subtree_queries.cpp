#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int max_n{200001};
ll val[max_n];
ll seg_size[max_n];
vector<ll> euler{};
ll seg[max_n * 4];
bool visited[max_n];

ll dfs(int node, const vector<vector<int>>& adj) {
    if(visited[node])
        return 0;
    
    visited[node] = true;
    euler.push_back(node);
    
    ll res{1};
    for(int child : adj[node]) {
        if(!visited[child])
            res += dfs(child, adj);
    }

    return seg_size[node] = res;     
}
void recalc(int idx)
{
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void build(int idx, int left, int right)
{
    if (left == right)
    {
        seg[idx] = val[left]; // leaf node, gets appened to the end
    }
    else
    {
        int mid{left + (right - left) / 2};
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        recalc(idx);
    }
}

ll query(int idx, int left, int right, int x, int y)
{
    if (x <= left && y >= right)
        return seg[idx];
    else
    {
        int mid{left + (right - left) / 2};
        ll res{};

        if (x <= mid)
        {
            res += query(2 * idx + 1, left, mid, x, y);
        }

        if (y > mid)
        {
            res += query(2 * idx + 2, mid + 1, right, x, y);
        }

        return res;
    }
}

void update(int idx, int left, int right, int pos, ll add)
{
    if (left == pos && left == right)
    {
        seg[idx] = add; // leaf node
    }
    else
    {
        int mid{left + (right - left) / 2};

        if (pos <= mid)
        {
            update(2 * idx + 1, left, mid, pos, add);
        }

        else
        {
            update(2 * idx + 2, mid + 1, right, pos, add);
        }

        recalc(idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, q{};
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    memset(visited, false, sizeof(visited));

    for(int i{}; i < n; ++i)
        cin >> val[i];
    
    while(--n) {
        ll x{}, y{};
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, adj);

    n = adj.size() - 2;
    build(0, 0, n);


    while(q--) {
        int type{};
        cin >> type;

        if(type == 2) {
            ll sub{};
            cin >> sub;

            cout << query(0, 0, n, --sub, sub + seg_size[sub + 1]) << '\n';
        }
        else {
            ll s{}, x{};
            cin >> s >> x;
            update(0, 0, n, s, x);
        }
    }

    return 0;
}