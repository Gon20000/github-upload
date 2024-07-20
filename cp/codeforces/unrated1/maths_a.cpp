#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod{998244353LL};

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
    u = multiply(u, u);

    if (n % 2 == 1)
    {
        u = multiply(u, x);
    }

    return u;  
}

vector<ll> fac{1};

ll getFac(int num)
{
    while (fac.size() <= num)
    {
        fac.push_back(multiply(fac.back(), fac.size()));
    }

    return fac[num];
}

ll getInvFac(ll n) {
    ll x{getFac(n)};

    return modpow(x, mod - 2);
}

void solve() {
    int n{};
    cin >> n;

    ll res{};
    ll left{};
    ll right{};
    ll questions{};

    while ((n--) != 0)
    {
        char x{};
        cin >> x;

        if (x == '>')
        {
            ++res;
        }
        else if (x == '<')
        {
            --res;
        }
        else
        {
            ++questions;
        }
    }

    if (questions < abs(res) || res % 2 != questions % 2)
    {
        cout << 0 << '\n';
    }
    else
    {
        if (res > 0)
        {
            left = abs(res);
        }
        else
        {
            right = abs(res);
        }

        ll out{getFac(questions)};
        questions -= abs(res);
        right += questions / 2;
        left += questions / 2;
        
        cout << multiply(out, multiply(getInvFac(left), getInvFac(right))) << '\n';
    }
};

int main()
{
    solve();

    return 0;
}