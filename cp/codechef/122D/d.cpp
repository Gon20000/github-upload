#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n{}, m{}, x{}, y{}, l{};
    cin >> n >> m >> x >> y >> l;
    

    ll a{(x - 1) / l + (n - x) / l + 1};
    ll b{(m - y) / l + (y - 1) / l + 1};
    ll res{static_cast<ll>(a*b)};

    cout << res << '\n';
}

int main() {
	// your code goes here
    int t{};
    cin >> t;
    while(t--)
        solve();
}
