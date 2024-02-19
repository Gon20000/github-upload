#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll compute(ll ind, ll minimum, ll maximum, const vector<ll>& a, const vector<ll>& b) {
    if (ind >= a.size())
        return maximum - minimum;

    ll res{INT_MAX};

    if(a[ind] != -1) {
        res = min(res, compute(ind + 1, min(minimum, a[ind]), max(maximum, a[ind]), a, b));
    }
    if (b[ind] != -1) {
        res = min(res, compute(ind + 1, min(minimum, b[ind]), max(maximum, b[ind]), a, b));
    }

    return res;
}

ll getHigher(ll x, const set<ll>& cont) {
    auto itr{cont.lower_bound(x)};

    if(itr == cont.end())
        return -1;
    else {
        return *itr;
    }
}

ll getLower(ll x, const set<ll>& cont) {
    auto itr{cont.lower_bound(x)};

    if(itr == cont.begin()) {
        return -1;
    }
    else {
        return *(--itr);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    ll res{INT_MAX};
    vector<ll> a(n);
    set<ll> b{};
    set<ll> c{};
    set<ll> d{};

    for(int i{}; i < n; ++i)
        cin >> a[i];
    for(int i{}; i < n; ++i) {
        ll x{};
        cin >> x;
        b.insert(x);
    }
    for(int i{}; i < n; ++i) {
        ll x{};
        cin >> x;
        c.insert(x);
    }
    for(int i{}; i < n; ++i) {
        ll x{};
        cin >> x;
        d.insert(x);
    }

    for(ll x : a) {
        vector<ll> lower{x, getLower(x, b), getLower(x, c), getLower(x, d)};
        vector<ll> higher{x, getHigher(x, b), getHigher(x, c), getHigher(x, d)};
        res = min(res, compute(0, INT_MAX, INT_MIN, lower, higher));
    }

    cout << res << '\n';

    return 0;
}