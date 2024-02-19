#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll diffMod(ll element, ll mod) {
    if(element % mod == 0)
        return 0;
    
    return mod - (element % mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while(t--) {
        ll n{}, x{}, y{};
        cin >> n >> x >> y;

        map<ll, map<ll, ll>> a{};

        ll res{};
        for(int i{}; i < n; ++i) {
            ll inp{};
            cin >> inp;

            ll mod_x{diffMod(inp, x)};
                
            res += a[mod_x][inp % y];

            ++a[inp % x][inp % y];        
        }

        cout << res << '\n';
    }

    return 0;
}