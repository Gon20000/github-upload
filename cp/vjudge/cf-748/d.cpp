#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{};
    cin >> n;

    set<ll> arr{};
    while(n--) {
        int x{}; cin >> x;
        arr.insert(x);
    }

    ll prev{*arr.rbegin()}, res{INT_MAX};

    for(auto it{++arr.rbegin()}; it != arr.rend(); ++it) {
        res = min(res, prev - *it);
        prev = *it;
    }

    cout << (res == INT_MAX ? -1 : res) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while(t--)
        solve();
        
    return 0;
}