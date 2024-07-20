#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod{static_cast<ll>(1e9) + 7};

ll modPow(ll x, ll n) {
    if(n == 0)
        return 1 % mod;
    
    ll res{modPow(x, n / 2)};
    res = (res * res) % mod;

    if(n % 2 == 1)
        res = (res * x) % mod;
    
    return res;
}

ll maxSum(vector<ll>& arr) {
    ll maxSoFar{0}, curr{};

    for(ll x : arr) {
        curr = max(curr, 0ll) ;
        curr += x;
        maxSoFar = max(curr, maxSoFar); 
    }

    return maxSoFar;
}

void solve() {
    int n{}, k{};
    cin >> n >> k;

    ll res{};
    vector<ll> arr(n);
    for(ll& x : arr) {
        cin >> x;
        res += x;
    }

    ll maxS{maxSum(arr)};
    ll add{((maxS) * (1 - modPow(2, k)))/(1 - 2)};

    cout << ((res % mod + add % mod) + mod) % mod << '\n';
}

int main() {
    int t{};
    cin >> t;
    freopen("a.out", "w", stdout);

    while(t--)
        solve();

    return 0;
}