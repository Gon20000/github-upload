#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{};
    int k{};
    cin >> n >> k;

    map<ll, ll> res{};
    for(int i{}; i < n; ++i) {
        ll x{};
        cin >> x;

        ++res[x % k];
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    //cin >> t;

    while ((t--) != 0)
    {
        solve();
    }

    return 0;
}