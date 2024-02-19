#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using node_t = pair<ll, ll>;

const ll max_size{static_cast<ll>(20) + 1};
ll arr[max_size];
ll seg[4 * max_size];

bool compare(node_t x, node_t y) {
    return x.first + x.second == y.first + y.second ? y.second > x.second : x.first + x.second > y.first + y.second;
}

void print(vector<ll> arr) {
    for(int i{}; i < arr.size() - 1; ++i)
        cout << arr[i] << ' ';
    cout << arr[arr.size() - 1] << '\n';
}

void recalc(ll idx)
{
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void build(ll idx, ll left, ll right)
{
    if (left == right)
    {
        seg[idx] = arr[left]; // leaf node, gets appened to the end
    }
    else
    {
        ll mid{left + (right - left) / 2};
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        recalc(idx);
    }
}

ll query(ll idx, ll left, ll right, ll x, ll y)
{
    if (x <= left && y >= right)
        return seg[idx];
    else
    {
        ll mid{left + (right - left) / 2};
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

void update(ll idx, ll left, ll right, ll pos, ll add)
{
    if (left == pos && left == right)
    {
        seg[idx] = add; // leaf node
    }
    else
    {
        ll mid{left + (right - left) / 2};

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

void solve() {
    ll n{};
    cin >> n;

    vector<node_t> dp(n);

    for(ll i{}; i < n; ++i) {
        arr[i] = 1;
        cin >> dp[i].first;
        dp[i].second = i;    
    }

    sort(dp.begin(), dp.end(), compare);
    build(0, 0, n - 1);

/*         for(ll i{}; i < 5; ++i) {
        cout << query(0, 0, 4, 0, i) << '\n';
    } */

    vector<ll> res{};
    for(auto [element, idx] : dp) {
        ll far{query(0, 0, n - 1, 0, idx)};
        ll curr{element + far};
        if(res.empty() || curr != res.back())
            res.push_back(curr);
        
        update(0, 0, n - 1, idx, 0);
    }

    print(res);
}

int main() {
    int t{};
    cin >> t;

    while(t--)
        solve();


    return 0;
}