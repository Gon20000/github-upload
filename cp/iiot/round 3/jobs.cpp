#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ratio_t = pair<ll, ll>;

const int k{static_cast<int>(25e4) + 1};

bool compare(ratio_t x, ratio_t y) {
    if(x.first == y.first)
        return x.first >= y.first;
    
    return x.first * y.second <= y.first * x.second;
}

int main() {
    int n{}, m{};
    cin >> n >> m;

    vector<ll> t(n), p(n);
    vector<ll> dp(k);

    for(int i{}; i < n; ++i)
        cin >> t[i];
    
    for(int i{}; i < n; ++i) {
        cin >> p[i];
    }
    
    for(int i{}; i < k; ++i) {
        for(int j{}; j < n; ++j) {
            if(i + t[j] < k)
                dp[i + t[j]] = max(dp[i + t[j]], dp[i] + p[j]);
        }
    }

    if(m < k) {
        cout << dp[m] << '\n';
        return 0;
    }

    ll res{};
    for(int i{k}; i > 0; --i) {
        res = max(res, dp[i] * (m / i) + dp[m % i]);
        
    }

    cout << res << '\n';

    return 0;
}