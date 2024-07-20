#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{static_cast<ll>(1e9) + 7};

ll multiply(ll x, ll y) {
    return (x % mod * (y % mod)) % mod;
}

void solve() {
    int n{};
    cin >> n;

    vector<ll> arr(n);
    for(ll& x : arr) {
        cin >> x;
    }

    sort(arr.begin(), arr.end());
    ll res{arr[0]};

    for(int i{1}; i < arr.size(); ++i) {
        if(arr[i] < 0 && i < arr.size() - 1 && arr[i + 1] < 0) {
                res = multiply(res, arr[i]);
                continue;
        }

        res = min(res, res * arr[i]) % mod;        
    }

    cout << (res + mod) % mod << '\n';
}

int main() {
    int t{};
    cin >> t;
    
    while(t--)
        solve();
}