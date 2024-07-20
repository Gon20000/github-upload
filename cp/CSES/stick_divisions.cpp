#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> m{};

ll solve(ll sz) {
    if(m.count(sz)) {
        --m[sz];
        if(m[sz] == 0)
            m.erase(sz);
    
        return 0;
    }

    ll sz1{max(sz / 2, *m.rbegin())}
}

int main() {
    ll x{}, n{}, res{};
    cin >> x >> n;

    for(int i{}; i < n; ++i) {
        ll e{};
        cin >> e;

        ++m[e];
    }
    
    for(int i{}; i < n - 1; ++i) {
        res += x;
        x -= arr[i];
    }

    cout << res << '\n';    
}