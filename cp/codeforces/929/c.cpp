#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve()
{
    ll a{}, b{}, l{};
    cin >> a >> b >> l;
    ll res{};


    int k{};
    set<int> check{};
    for (ll x{1}; k < 32 && x <= l; x *= a, ++k)
    {
        int j{};
        for (ll y{1}; j < 32 && y <= l; y *= b, ++j)
        {
            if (l % (y * x) == 0)
            {
                if(check.count(l / (y * x)) > 0)
                    continue;
                
                check.insert(l / (y * x));
                ++res;
            }
        }
    }

    cout << res << '\n';
}

int main()
{
    int t{};
    cin >> t;

    //freopen("out.txt", "w", stdout);

    while (t--)
        solve();

    return 0;
}
