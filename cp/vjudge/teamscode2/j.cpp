#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{998244353};

void solve() {
    ll l{};
    ll r{};
    cin >> l >> r;

    vector<ll> psum(r-l+2);
    for(ll i{l + 1}; i <= r + 1; ++i) {
        ll res{};
        ll x{i};
        while(x > 0) {
            res += static_cast<ll>(x % 10 == 3);
            x /= 10;
        }
        
        psum[i - l] += res + psum[i - l - 1];
    }

    ll res{};
    for(int i{1}; i < psum.size(); ++i) {
        for(int j{i}; j < psum.size(); ++j) {
            res += psum[j] - psum[i - 1];
            res %= mod;
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while ((t--) != 0)
    {
        solve();
    }

    return 0;
}
