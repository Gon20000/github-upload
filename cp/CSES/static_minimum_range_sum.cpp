#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll max_size{200000}; 
ll seg[4 * max_size];
ll arr[max_size];


void recalc(int idx) {
   seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]); 
}

void build(int idx, int left, int right) {
    if (left == right) {
        seg[idx] = arr[left]; // leaf node
    }
    else {
        int mid {left + (right - left)/ 2};
        build(2 * idx + 1, left, mid);
        build(2 * idx + 2, mid + 1, right);
        recalc(idx);
    }
}

ll query(int idx, int left, int right, int x, int y) {
    if (x <= left && y >= right) {
        return seg[idx];
    }
    else {
        ll res {static_cast<ll>(1e9)};
        int mid {left + (right - left) / 2};
        
        if (x <= mid) {
            res = min(res, query(2 * idx + 1, left, mid, x, y));
        }

        if (mid < y) {
            res = min(res, query(2 * idx + 2, mid + 1, right, x, y));
        }
        
        return res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    ll n{}, q{};
    cin >> n >> q;

    
    for(ll i{}; i < n; ++i)  {
        ll x{};
        cin >> x;

        arr[i] = x;
    }

    build(0, 0, n - 1);

    while (q--) {
        ll low{}, high{};
        cin >> low >> high;

        cout << query(0, 0, n - 1, low - 1, high - 1) << '\n';
    }

    return 0;
}