#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n{};
    cin >> n;

    map<ll, map<ll, ll>> res{};
    map<ll, ll> store{};

    ll ans{};
    while (n--)
    {
        ll x{};
        cin >> x;

        if(res.count(x) > 0)
            store[x] = max(store[x], ++res[x][x^2147483647]);
        else
            store[x ^ 2147483647] = max(store[x ^ 2147483647], ++res[x ^ 2147483647][x]);
    }

    for(auto x : store)
        ans += x.second;
    cout << ans << '\n';
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t{};
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}