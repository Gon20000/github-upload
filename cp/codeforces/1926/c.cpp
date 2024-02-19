#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> dp[7][50][2];
string num{};

int digit(int i) {
    return num[i] - '0';
}

pair<ll, ll> solve(int idx, ll sum, bool above) {
    if(idx > 5)
        return {0, 1};
    
    if(dp[idx][sum][above].first != -1)
        return dp[idx][sum][above];
    
    int lim{above ? 9 : digit(idx)};

    pair<ll, ll> res{};
    for(int i{}; i <= lim; ++i)  {
        bool newAbove{above || i < digit(idx)};

        pair<ll, ll> curr{solve(idx + 1, sum + i, newAbove)};
        curr.first += i * max(1ll, curr.second);
        res.second += curr.second;
        res.first += curr.first;
    }

    return dp[idx][sum][above] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while(t--) {
        cin >> num;
        while(num.size() < 6) {
            num = '0' + num;
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 0).first << '\n';
    }
}