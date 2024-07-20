#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod{static_cast<int>(1e9) + 7};

ll multiply(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}

ll modpow(ll x, ll n) {
    if (n == 0)
    {
        return 1 % mod;
    }

    ll u{modpow(x, n / 2)};
    u = (u * u) % mod;

    if (n % 2 == 1)
    {
        u = (u * x) % mod;
    }

    return u;  
}

vector<ll> fac{1};
vector<ll> inv_fac{modpow(1, mod - 2)};

ll getFac(int num)
{
    while (fac.size() <= num)
    {
        fac.push_back(multiply(fac.back(), fac.size()));
        inv_fac.push_back(modpow(fac.back(), mod - 2));
    }

    return fac[num];
}

int main()
{
    ll n{};
    cin >> n;

    for (ll i{}; i < n; ++i)
    {
        ll x{};
        ll y{};
        cin >> x >> y;

        ll facX{getFac(x)};
        ll facY{inv_fac[y]};

        cout << (multiply(facX, multiply(facY, inv_fac[x - y]))) << '\n';
    }
}