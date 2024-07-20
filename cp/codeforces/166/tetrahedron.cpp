#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD{1000000007};

ll add(ll x, ll y)
{
    return (x % MOD + y % MOD) % MOD;
}

ll multiply(ll x, ll y)
{
    return (x % MOD * y % MOD) % MOD;
}

int main()
{
    int n{};
    cin >> n;

    vector<pair<ll, ll>> dp(n + 1);
    dp[1] = {1, 0};

    int i{1};
    while (i++ < n)
    {
        dp[i] = {add(multiply(dp[i - 1].first, 2), dp[i - 1].second),
                 multiply(dp[i - 1].first, 3)};
    }

    cout << dp[n].second << '\n';

    return 0;
}