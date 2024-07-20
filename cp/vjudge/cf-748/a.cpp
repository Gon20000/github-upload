#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a{}, b{}, c{};
    cin >> a >> b >> c;

    cout << max(0ll, max(b, c) + 1 - a) << ' ' <<  max(0ll, max(a, c) + 1 - b) << ' ' << max(0ll, max(b, a) + 1 - c) << '\n';
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