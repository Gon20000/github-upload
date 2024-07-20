#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod{static_cast<ll>(1e9) + 7};

ll add(ll x, ll y) {
    return (x % mod + y % mod)  % mod;
}

ll mult(ll x, ll y) {
    return (x % mod * y % mod) % mod;
}

ll modpow(ll x, ll n) {
    if(n == 0)
        return 1 % mod;
    
    ll u{modpow(x, n / 2) % mod};
    u = (u * u) % mod;
    
    if(n % 2 == 1)
        u *= x;
    
    return u % mod;
}

ll summation(ll n) {
    if(n < 1)
        return 0;
    
    return static_cast<ll>(n/2.0 * (n + 1)) % mod;
}

ll geoSeries(ll a, ll r, ll n) {
    return mult(a, 1 - modpow(r, n)) / (1-r);
}

ll top(ll n) {
    if(n < 0)
        return 0;
    
    return  geoSeries(1, 2, n) + 0 - geoSeries(2, 2, n) + n * modpow(2, n);
}

ll getRow(ll n) {
    return modpow(2, n) * (top(n) + summation(n) + )     
}

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    //cin >> t;
   
    while(t--)
        solve();
    
    return 0;
}