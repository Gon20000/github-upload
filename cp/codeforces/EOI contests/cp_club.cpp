#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    ll val{};
    ll skill{};

    node() {
    }

    node(ll x, ll y) {
        val = x;
        skill = y;
    }
};

const ll max_size{15};
ll arr[max_size];
ll psum[max_size];
node seg[4 * max_size];

void recalc(int idx, int left, int right) {
    seg[idx] = node(
        2 * (right - left + 1) * abs(psum[right] - psum[left - 1]),
        max(seg[2 * idx].skill, seg[2 * idx + 1].skill));
}

void build(int idx, int left, int right) {
    if (left == right)
        seg[idx] = node(2 * arr[left], arr[left]); // leaf node
    else {
        int mid {left + (right - left) / 2};
        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);
        recalc(idx, left, right);
    }
}

ll query(int idx, int left, int right, int x, int y, ll target) {
    if (seg[idx].val < target || left > y || right < x || seg[idx].val == 0 || seg[idx].skill == 0) {
        return LLONG_MAX;
    }
    
    int mid {left + (right - left) / 2};
    ll res{seg[idx].skill};

    if (x <= mid) {
        res = min(res, query(2 * idx, left, mid, x, y, target));
    }
    
    if (y > mid) {
        res = min(res, query(2 * idx + 1, mid + 1, right, x, y, target));
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // reset arr and psum

    ll n{}, q{};
    cin >> n >> q;

    for(int i{1}; i <= n; ++i) {
        cin >> arr[i];
        psum[i] = arr[i] + psum[i - 1];
    }


    build(1, 1, (1 << ll(ceil(log2(n)))));
    seg[1].val = 2 * n * psum[n];

    while(q--) {
        ll l{}, r{}, x{};
        cin  >> l  >> r  >>  x;
        ll res{query(1, 1, n, l, r, x)};
        if(res == LLONG_MAX)
            cout << -1;
        else
            cout << res << '\n';
    }

    return 0;
}