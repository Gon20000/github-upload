#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n{};
    cin >> n;

    ll curr{LLONG_MAX};
    vector<ll> arr{};
    for(ll i{1}; i <= n; ++i) {
        ll x{};
        cin >> x;

        if(x < curr) {
            arr.push_back(i);
            curr = x;
        }
    }

    cout << arr.size() << '\n';
    for(ll i{}; i < arr.size() - 1; ++i)
        cout << arr[i] << ' ';
    if(!arr.empty())
        cout << arr[arr.size() - 1] <<  '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t{};
    cin >> t;

    while(t--) {
        solve();
    }
}