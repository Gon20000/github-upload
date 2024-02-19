#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--) {
        
        ll a{}, b{}, n{};
        cin >> a >> b >> n;

        ll res{};
        multiset<ll> tools{};

        while(n--) {
            ll x{};
            cin >> x;
            tools.insert(x);
        }

        for(auto itr{tools.begin()}; itr != tools.end(); ++itr) {
            ll x{*itr};

            if(b + x > a) {
                res += b - 1;
                b = 1;
            }
            b = min(b + x, a);
        }        

        cout << res + b << '\n';
    }
}